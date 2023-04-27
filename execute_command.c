#include "sshell.h"

void execute(char *line)
{
	char **args;
	int check, status;
	pid_t pid;
	char *executable_path;

	/* Parse the input line into arguments */
	args = parse_arguments(line);

	/* If no arguments are provided, free the memory and return */
	if (args[0] == NULL)
	{
		free_args(args);
		return;
	}

	/* Check if the command is a built-in command and execute it */
	check = check_for_builtins(args[0], args);

	if (check == 1)
	{
		free_args(args);
	}
	else if (check == -1)
	{
		free_args(args);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* Fork a new process to execute the command */
		pid = fork();

		if (pid == 0) /* Child process */
		{
			executable_path = search_executable_in_path(args[0]);

			if (executable_path == NULL)
			{
				executable_path = args[0];
			}

			if (execve(executable_path, args, NULL) == -1)
			{
				perror("#Error");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0) /* Parent process */
		{
			waitpid(pid, &status, 0);
		}
		else /* Fork failed */
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		free_args(args);
	}
}


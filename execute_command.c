#include "sshell.h"

void execute(char *line)
{
	int status;
	pid_t pid;
	char *executable_path;
	char **args;

	/* Parse the input line into arguments */
	args = parse_arguments(line);

	/* If no arguments are provided, free the memory and return */
	if (args[0] == NULL)
	{
		return;
	}

	/* Check if the user has entered the 'exit' command */
	if (strcmp(args[0], "exit") == 0)
	{
		/* Free the memory allocated for args */
		free_args(args);
		exit(EXIT_SUCCESS);
	}

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
}

#include "sshell.h"

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
}

void execute(char *line)
{
	char **args;
	int check, status;
	pid_t pid;


    args = parse_arguments(line);

    if (args[0] == NULL) 
    {
        free_args(args);
        return;
    }


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

        if ((pid = fork()) == 0)
        {
            if (execve(args[0], args, NULL) == -1)
            {
                perror("simple_shell");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            waitpid(pid, &status, 0);
        }
        free_args(args);
    }
}

int check_for_builtins(char *command, char **args)
{
	int i;

	struct {
		char *name;
		void (*function)(char **args);
	} builtins[] = {
		{"ls", shell_ls},
		{"cat", shell_cat},
		{"echo", shell_echo},
		{"mkdir", shell_mkdir},
		{"rm", shell_rm},
		{"touch", shell_touch},
		{"cd", shell_cd},
		{"cp", shell_cp},
		{"mv", shell_mv},
		{"pwd", shell_pwd},
		{"exit", NULL},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].name != NULL; ++i)
	{
		if (strcmp(command, builtins[i].name) == 0)
		{
			if (builtins[i].function == NULL)
			{
				return -1; /* exit command*/
			}
			builtins[i].function(args);
			return 1;
		}
	}
	return 0;
}
char **parse_arguments(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "#cisfun$: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	if (token == NULL)
	{
		tokens[position] = NULL;
		return (tokens);
	}

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "#cisfun$: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return tokens;
}
void free_args(char **args)
{
	if (args != NULL)
	{
		free(args);
	}
}

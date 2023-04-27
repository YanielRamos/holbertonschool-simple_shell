#include "sshell.h"

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
}

void free_args(char **args)
{
	int i;
	if (args == NULL)
		return;

	if (args != NULL)
	{
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
	}
	free(args);
}

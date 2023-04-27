#include "sshell.h"

/**
 * prompt - function that prints the prompt
 * @void: no parameters needed
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
}

/**
 * free_args - function that free memory
 * @args: comando fthe user to be free
 */

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

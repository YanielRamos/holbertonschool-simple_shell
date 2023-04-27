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
	if (args != NULL)
	{
		free(args);
	}
}

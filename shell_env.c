#include "sshell.h"

int string_contains(const char *str, const char *substr)
{
	return (strstr(str, substr) != NULL);
}

void shell_env(char **args)
{
	extern char **environ;
	int i;
	int filter = 0;

	if (args[1] != NULL)
	{
		filter = 1;
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!filter || string_contains(environ[i], args[1]))
		{
			printf("%s\n", environ[i]);
		}
	}
}


#include "sshell.h"

/**
 * main - function of the shell
 * @void: no parameters needed
 * Return: 0 for success
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		prompt();
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			break;
		}

		if (!is_empty(line))
		{
			execute(line);
		}
	}

	free(line);
	return (0);
}

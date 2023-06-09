#include "sshell.h"

/**
 * main - function of the shell
 * @ac: argument counter
 * @argv: argument vector
 * Return: 0 for success
 */

int main(int ac, char **argv)
{
	ssize_t nread;
	char *line = NULL;
	size_t len = 0;
	char **args = NULL;
	(void)ac;
	(void)argv;

	while (1)
	{
		prompt();
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			break;
		}

		if (!is_empty(line))
		{
			execute(line);
		}

		/* Free the memory allocated for args and executable_path */
		if (args != NULL)
		{
			free_args(args);
		}
	}
	free(line);
	return (0);
}

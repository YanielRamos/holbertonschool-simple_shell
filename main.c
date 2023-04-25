#include "sshell.h"

int is_empty(const char *str)
{
	while (*str != '\0')
	{
	if (!isspace ((unsigned char) * str))
		return (0);
	str++;
	}
	return (1);
}

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
		execute(line);

		if (!is_empty(line))
		{
			execute(line);
		}
	}

	free(line);
	return (0);
}


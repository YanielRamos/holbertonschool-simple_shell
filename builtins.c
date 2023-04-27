#include "sshell.h"

void shell_ls(char **args)
{
	DIR *dir;
	struct dirent *entry;
	int count = 0;

	if (args[1] != NULL && args[2] != NULL)
		return;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("ls");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			printf("%s\n", entry->d_name);
			count++;
		}
	}
	closedir(dir);
}

void shell_cat(char **args)
{
	int fd;
	ssize_t bytesRead;
	char buffer[1024];

	if (args[1] == NULL)
	{
		fprintf(stderr, ": expected argument to \"cat\"\n");
		return;
	}
	fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		perror("cat");
		return;
	}

	while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
	{
		write(STDOUT_FILENO, buffer, bytesRead);
	}
	close(fd);
}

void shell_echo(char **args)
{
	int i;
	
	if (args[1] == NULL)
	{
		return;
	}

	for (i = 1; args[i] != NULL; i++)
	{
		printf("%s\n", args[1]);
		if (args[i + 1] != NULL)
			printf(" ");
	}
	printf("\n");
}

void shell_mkdir(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, ": expected argument to \"mkdir\"\n");
		return;
	}
	if (mkdir(args[1], 0755) == -1)
	{
		perror("mkdir");
	}
}

void shell_rm(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, ": expected argument to \"rm\"\n");
		return;
	}
	if (remove(args[1]) == -1)
	{
		perror("rm");
	}
}

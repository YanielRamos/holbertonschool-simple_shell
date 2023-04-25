#include "sshell.h"

void shell_ls(char **args)
{
	DIR *dir;
	struct dirent *entry;
	(void)args;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("simple_shell");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
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
		fprintf(stderr, "#cisfun: expected argument to \"cat\"\n");
		return;
	}
	fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		perror("#cisfun");
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
	if (args[1] == NULL)
	{
		printf("\n");
		return;
	}
	printf("%s\n", args[1]);
}

void shell_mkdir(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "#cisfun: expected argument to \"mkdir\"\n");
		return;
	}
	if (mkdir(args[1], 0755) == -1)
	{
		perror("#cisfun");
	}
}

void shell_rm(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "#cisfun: expected argument to \"rm\"\n");
		return;
	}
	if (remove(args[1]) == -1)
	{
		perror("#cisfun");
	}
}

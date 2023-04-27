#include "sshell.h"

char *search_executable_in_path(const char *executable)
{
	char *path = getenv("PATH");
	char *path_copy, *dir, *full_path;
	struct stat st;

	if (path == NULL)
	{
		return (NULL);
	}

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(executable) + 2);
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, executable);

		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return full_path;
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

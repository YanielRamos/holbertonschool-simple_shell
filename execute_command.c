#include "sshell.h"

void execute(char *line)
{
        char **args;

        pid_t pid = fork();
        if (pid == -1)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
                args = parse_arguments(line);
                execvp(args[0], args);
                perror(args[0]);
		free_args(args);
                exit(EXIT_FAILURE);
        }
        else
        {
                waitpid(pid, NULL, 0);
        }
}

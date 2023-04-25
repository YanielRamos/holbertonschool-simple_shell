#include "sshell.h"

void shell_touch(char **args)
{
        int fd;

        if (args[1] == NULL)
        {
                fprintf(stderr, "simple_shell: expected argument to \"touch\"\n");
                return;
        }
        fd = open(args[1], O_RDWR | O_CREAT, 0644);

        if (fd == -1)
        {
                perror("simple_shell");
        }
        else
        {
                close(fd);
        }
}

void shell_cd(char **args)
{
        if (args[1] == NULL)
        {
                fprintf(stderr, "simple_shell: expected argument to \"cd\"\n");
                return;
        }
        if (chdir(args[1]) != 0)
        {
                perror("simple_shell");
        }
}

void shell_cp(char **args)
{

        int src_fd, dest_fd;
        ssize_t bytesRead;
        char buffer[1024];

        if (args[1] == NULL || args[2] == NULL)
        {
                fprintf(stderr, "simple_shell: expected 2 arguments to \"cp\"\n");
                return;
        }
        src_fd = open(args[1], O_RDONLY);
        dest_fd = open(args[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (src_fd == -1 || dest_fd == -1)
        {
                perror("simple_shell");
        }
        else
        {
                while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0)
                {
                        write(dest_fd, buffer, bytesRead);
                }
                close(src_fd);
                close(dest_fd);
        }
}

void shell_mv(char **args)
{
        if (args[1] == NULL || args[2] == NULL)
        {
                fprintf(stderr, "simple_shell: expected 2 arguments to \"mv\"\n");
                return;
        }
        if (rename(args[1], args[2]) == -1)
        {
                perror("simple_shell");
        }
}

void shell_pwd(char **args)
{
    char cwd[1024];
    (void)args;

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("simple_shell");
        return;
    }

    printf("%s\n", cwd);
}

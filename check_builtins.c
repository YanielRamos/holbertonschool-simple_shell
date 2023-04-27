#include "sshell.h"

int check_for_builtins(char *command, char **args)
{
        int i;

        struct
        {
                char *name;
                void (*function)(char **args);
        } builtins[] = {
                {"ls", shell_ls},
                {"cat", shell_cat},
                {"echo", shell_echo},
                {"mkdir", shell_mkdir},
                {"rm", shell_rm},
                {"touch", shell_touch},
                {"cd", shell_cd},
                {"cp", shell_cp},
                {"mv", shell_mv},
                {"pwd", shell_pwd},
                {"exit", NULL},
                {NULL, NULL}
        };

        for (i = 0; builtins[i].name != NULL; ++i)
        {
                if (strcmp(command, builtins[i].name) == 0)
                {
                        if (builtins[i].function == NULL)
                        {
                                return (-1); /* exit command*/
                        }
                        builtins[i].function(args);
                        return (1);
                }
        }
        return (0);
}

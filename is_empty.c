#include "sshell.h"

/**
 * is_empty - function that verify if the user types somehting in the prompt
 * @str: string in the prompt
 * Return: Return 1 for success
 */

int is_empty(const char *str)
{
	while (*str != '\0')
	{
	if (!isspace((unsigned char) *str))
		return (0);
	str++;
	}
	return (1);
}

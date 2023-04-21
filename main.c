#include "shell.h"

/** main - funtcion
 * @ac: argument counter
 * @argv: argument vector
 * Return: 0 success
 */

int main(int ac, char ** argv)
{
	char *prompt = "(Y&L)$";
	char *lptr;
	size_t n = 0;

	printf("%s", prompt);
	getline(&lptr, &n, stdin);
	printf("%s\n", lptr);

	free(lptr);
	return (0);
}

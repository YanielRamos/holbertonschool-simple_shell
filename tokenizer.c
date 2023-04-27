#include "sshell.h"

#define TOKEN_BUFSIZE 64

char **parse_arguments(char *line)
{
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token_start, *token_end;

	if (!tokens)
	{
		fprintf(stderr, "#: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token_start = line;
	while (*token_start != '\0')
	{
		// Skip leading whitespace
		while (isspace((unsigned char)*token_start))
		{
			token_start++;
		}
		if (*token_start == '\0')
		{
			break;
		}
		/* If the argument starts with a double quote, find the matching closing quote*/
		if (*token_start == '"')
		{
			token_start++;
			token_end = strchr(token_start, '"');
			if (token_end == NULL)
			{
				fprintf(stderr, "Unmatched double quote\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			token_end = token_start;
			while (*token_end != '\0' && !isspace((unsigned char)*token_end))
			{
				token_end++;
			}
		}

		/* Allocate memory for the token and copy the token */
		tokens[position] = malloc(token_end - token_start + 1);
		strncpy(tokens[position], token_start, token_end - token_start);
		tokens[position][token_end - token_start] = '\0';
		position++;

		/* If buffer size is not enough, reallocate memory */
		if (position >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, ": allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token_start = (*token_end == '"') ? token_end + 1 : token_end;
	}

	tokens[position] = NULL;
	return (tokens);
}

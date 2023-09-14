#include "shell.h"

/**
 * split_line - split the input string into
 * array of individual tokens
 * @line: line to be split
 *
 * Return: array of individual tokens
 */
char **split_line(char *line)
{
	int len = 0;
	int mem_capacity = 16;
	char **tokens = NULL;
	char **temp;
	char *delimiters;
	char *token;

	tokens = malloc(mem_capacity * sizeof(char *));

	delimiters = " \t\r\n";
	token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[len] = token;
		len++;

		if (len >= mem_capacity)
		{
			mem_capacity = (int) (mem_capacity * 1.5);
			temp = realloc(tokens, mem_capacity * sizeof(char *));
			if (temp == NULL)
			{
				free(tokens);
				return (NULL);
			}
			tokens = temp;
		}
		token = strtok(NULL, delimiters);
	}

	tokens[len] = NULL;
	return (tokens);
}

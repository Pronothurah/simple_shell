#include "shell.h"

/**
 * read_line - read a single line of input from stdin
 *
 * Return: void
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buflen = 0;

	getline(&line, &buflen, stdin);

	return (line);
}

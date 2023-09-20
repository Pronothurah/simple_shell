#include "main.h"

/**
 * free_args - frees argument array
 * @args: array of arguments passed
 *
 * Return: void
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}

	free(args);
}

/**
 * __exit - exit process
 * @args: array of arguments passed
 * @input: input read
 *
 * Return: void
 */
void __exit(char *input, char **args)
{
	free(input);
	free_args(args);
	exit(0);
}

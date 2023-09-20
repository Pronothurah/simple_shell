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
		if (args[i])
		{
			free(args[i]);
		}
	}

	free(args);
}

/**
 * __exit - exit process
 * @args: array of arguments passed
 *
 * Return: void
 */
void __exit(char **args)
{
	free_args(args);
	exit(0);
}

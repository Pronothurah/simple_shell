#include "main.h"

/**
 * free_args - frees argument array 
 * @args: array of arguments passed
 * 
 * Return: freed arguments
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

void __exit(char *input, char *path)
{
	free(input);
	free(path);
	free_args(args);
	exit(0);
}

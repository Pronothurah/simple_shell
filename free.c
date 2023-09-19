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

#include "main.h"

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

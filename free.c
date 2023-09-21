#include "main.h"

/**
 * free_tokens - frees arguments
 * @tokens: array of arguments passed
 * @tmp: input string
 * @i: index
 *
 * Return: void
 */
void free_tokens(char **tokens, char *tmp, int i)
{
	free(tmp);
	free(tokens[i]);
	free(tokens);
}

/**
 * free_args - frees argument array
 * @args: array of arguments passed
 *
 * Return: void
 */
void free_args(char **args)
{
	free(*args);
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

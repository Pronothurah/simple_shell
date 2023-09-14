#include "shell.h"

/**
 * _strlen - a function that gets a length of a tring
 *
 * @str: sting to get length
 *
 * Return: length of string
 */
int _strlen(const char *str)
{
	int length = 0;

	while (*str++)
		length++;

	return (length);
}


/**
 * _print - prints characters to the standard output
 * @str: input string
 *
 * Return: void
 */
void _print(const char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

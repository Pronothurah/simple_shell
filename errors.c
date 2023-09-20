#include "main.h"

/**
 * show_errors - global error manager
 * @name: name of the program
 * @cmd: name of the command
 * @status: status of the program
 *
 * Return: void
 */
void show_errors(int status, char *name, char *cmd)
{
	if (status == 127)
	{
		error_1_output(name, cmd);
	}
}

/**
 * error_1_output - prints not found error
 * @name: name of the program
 * @cmd: name of the command
 *
 * Return: void
 */
void error_1_output(char *name, char *cmd)
{
	int i;

	_print_error(name);
	_print_error(": 1: ");

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '\n')
		{
			cmd[i] = '\0';
		}
	}

	_print_error(cmd);
	_print_error(": not found\n");
}

/**
 * _print_error - prints characters to the stderror output
 * @str: input string
 *
 * Return: void
 */
void _print_error(const char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}

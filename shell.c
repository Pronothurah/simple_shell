#include "shell.h"

/**
 * main - #include "main.h"
 *
 * Return: always 0
 */
int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		shell_prompt();
		input = read_line();
		args = split_line(input);

		if (args[0] != NULL)
		{
			execute_a_command(args);
		}

		free(input);
		free(args);
	}
	return (0);
}

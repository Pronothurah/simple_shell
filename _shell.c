#include "shell.h"

/**
 * main - #include "main.h"
 *
 * Return: always 0
 */
int main(__attribute__((__unused__)) int argc, char **argv)
{
	char input[1024];
	char* args[64];

	while (1)
	{
		shell_prompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strlen(input) - 1] = '\0';

		parse_input(input, args);

		execute_command(args);
	}
	return (0);
}

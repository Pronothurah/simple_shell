#include "main.h"

/**
 * catch_ctrlc - catch ctrl + C signal
 * @sig: signal value
 *
 * Return: void
 */
void catch_ctrlc(__attribute__((__unused__)) int sig)
{
	_putchar('\n');
	exit(0);
}

/**
 * execute_normal_mode - interactive mode
 *
 * Return: exit status (int)
 */
int execute_normal_mode(void)
{
	int flag = 0;
	size_t len = 0;
	int byteRead = 0;
	char *input = NULL;

	_print("($) ");
	byteRead = getline(&input, &len, stdin);
	if (byteRead == -1)
	{
		free(input);
		printf("\n");
		return (-1);
	}

	if (input[0] == '\0' || input[1] == '\0')
		flag = 1;

	if (flag == 0)
	{
		flag = execute(input, byteRead);
		free(input);
	}

	return (flag);
}

/**
 * main - check code
 * @ac: argument count
 * @av: argument vector
 *
 * Return: int
 */
int main(__attribute__((__unused__)) int ac, char **av)
{
	int res = 0;

	if (!isatty(STDIN_FILENO))
	{
		res = execute_pipe_mode(STDIN_FILENO);
		if (res > 0)
			perror(av[0]);
	}
	else
	{
		signal(SIGINT, catch_ctrlc);
		while (1)
		{
			res = execute_normal_mode();
			if (res == -1)
				break;

			if (res > 0)
				perror(av[0]);
		}
	}

	return (res);
}

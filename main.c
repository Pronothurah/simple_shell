#include "main.h"

/**
 * catch_ctrlc - catch ctrl + C signal
 * @sig: signal value
 *
 * Return: void
 */
void catch_ctrlc(__attribute__((__unused__)) int sig)
{
	printf("\n");
	exit(0);
}

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input;
	size_t len = 0;
	int r;
	char *path = _get_env("PATH");
	int flag = 0;
	int res;

	if (path == NULL)
	{
		free(path);
		printf("Unable to launch\n");
		return (1);
	}

	if (!isatty(STDIN_FILENO))
	{
		res = execute_pipe_mode(STDIN_FILENO, path);
	}
	else
	{
		signal(SIGINT, catch_ctrlc);
		while (1)
		{
			flag = 0;
			_print("($) ");
			r = getline(&input, &len, stdin);
			if (r == -1)
			{
				printf("\n");
				break;
			}

			if (input[0] == '\0' || input[1] == '\0')
				flag = 1;

			if (flag == 0)
				res = execute(input, path, r);
		}

		free(input);
	}

	free(path);
	return (res);
}

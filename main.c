#include "main.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main()
{
	char *input;
	int r;
	size_t len = 0;
	char *args[64];
	pid_t child_pid;

	input = malloc(sizeof(char) * 1024);
	if (input == NULL)
	{
		free(input);
	}

	while (1)
	{
		printf("($) ");
		r = getline(&input, &len, stdin);
		if (r == -1)
		{
			printf("\n");
			break;
		}

		input[strlen(input) - 1] = '\0';
		args[0] = input;
		args[1] = NULL;
		args[2] = (char *)0;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
		}

		if (child_pid == 0)
		{
			r = execve(args[0], args, NULL);

			if (r == -1)
			{
				printf("No such file or directory\n");
			}
		}
		else
		{
			wait(NULL);
		}
	}

	free(input);

	return (0);
}
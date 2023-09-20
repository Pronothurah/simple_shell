#include "main.h"

/**
 * execute - executes arguments
 * @input: input string
 * @length: length of the string
 *
 * Return: integer
 */
int execute(char *input, int length)
{
	char **args;
	pid_t child_pid;
	int status, flag = 0;

	args = parse_input(input, length);
	if (args[0] == NULL)
		flag = 127;
	else if (_strcmp(args[0], "exit") == 0)
		__exit(input, args);
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error child:");
			return (1);
		}

		if (child_pid == 0)
		{
			execve(args[0], args, __environ);
			return (errno);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			flag = WEXITSTATUS(status);
		}
	}

	free_args(args);
	return (flag);
}

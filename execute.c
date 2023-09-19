#include "main.h"

/**
 * execute - executes arguments
 * @input: input string
 * @path: path of the global path argument
 * @length: length of the string
 *
 * Return: integer
 */
int execute(char *input, char *path, int length, char *av)
{
	char **args;
	pid_t child_pid;
	int status;
	int flag = 0;

	args = parse_input(input, path, length);
	if (args[0] == NULL)
	{
		error_1_output(av, input);
		return (127);
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		__exit(input, path, args);
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
			perror("Error:");

		if (child_pid == 0)
		{
			if ((execve(args[0], args, __environ)) == -1)
			{
				error_1_output(av, input);
				return (127);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				int exit_code = WEXITSTATUS(status);

				flag = exit_code;
			}
		}
	}
	free_args(args);
	return (flag);
}

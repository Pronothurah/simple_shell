#include "main.h"

/**
 * not_found_error - prints not found error
 * @name: name of the program
 * @cmd: name of the command
 *
 * Return: integer
 */
int not_found_error(char *name, char *cmd)
{
	/*error_1_output(name, cmd);*/
	(void)cmd;
	perror(name);
	return (127);
}

/**
 * execute - executes arguments
 * @input: input string
 * @path: path of the global path argument
 * @length: length of the string
 * @av: argument vector
 *
 * Return: integer
 */
int execute(char *input, char *path, int length, char *av)
{
	char **args;
	pid_t child_pid;
	int status, flag = 0;

	args = parse_input(input, path, length);
	if (args[0] == NULL || args[1])
		return (not_found_error(av, input));
	else if (_strcmp(args[0], "exit") == 0)
		__exit(input, path, args);
	else
	{
		child_pid = fork();
		if (child_pid == -1)
			perror("Error:");

		if (child_pid == 0)
		{
			if ((execve(args[0], args, __environ)) == -1)
				return (not_found_error(av, input));
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

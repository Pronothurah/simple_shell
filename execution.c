#include "shell.h"

/**
 * execute_a_command - executes arguments passed to cli
 * @args: pointer to arguments passed
 *
 * Return: void;
 */

void execute_a_command(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error:");
			exit(1);
		}
	}
	else if (child_pid > 0)
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Error:");
		exit(-1);
	}
}

#include "main.h"

/**
 * execute_pipe_mode - implements the pipe operator
 * @fd: file descriptor from stdin
 * @path: path in global environment
 *
 * Return: integer
 */
int execute_pipe_mode(int fd, char *path)
{
	char pipe[1024];
	char *str = NULL;
	char *s;
	ssize_t bytesRead;
	char *tmp;
	int len = 0;
	int res;

	if (pipe == NULL)
		return (1);

	bytesRead = read(fd, pipe, 1024);
	if (bytesRead < 0)
		return (1);

	pipe[bytesRead] = '\0';
	if (pipe[0] == '\0' || pipe[1] == '\0')
		return (1);

	str = custom_strdup(pipe);
	s = strtok(str, "\n");

	while (s != NULL)
	{
		tmp = custom_strdup(s);
		len = _strlen(tmp);
		res = execute(tmp, path, len);
		s = strtok(NULL, "\n");
		free(tmp);
	}

	free(str);

	return (res);
}

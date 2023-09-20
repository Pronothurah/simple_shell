#include "main.h"

/**
 * count_whitespace - count whitespace in string
 * @str: input string
 *
 * Return: integer
 */
int count_whitespace(char *str)
{
	int count = 0;
	int i;

	if (str[0] == '\0')
	{
		return (-1);
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}

	return (count);
}

/**
 * format_pipe - format input
 * @pipe: given input
 * @tokens: array of strings pointer
 *
 * Return: integer
 */
int format_pipe(char *pipe, char **tokens)
{
	int count = 0;
	int i;
	int length;
	int start = 0;
	int index = 0;

	for (i = 0; pipe[i]; i++)
	{
		if (pipe[i] == '\n')
		{
			count++;
		}
	}

	for (i = 0; pipe[i]; i++)
	{
		if (pipe[i] == '\n')
		{
			length = i - start;
			tokens[index] = (char *)malloc(length + 1);

			_strncpy(tokens[index], pipe + start, length);
			tokens[index][length] = '\0';
			index++;
			start = i + 1;
		}
	}

	return (count);
}

/**
 * execute_pipe_mode - implements the pipe operator
 * @fd: file descriptor from stdin
 * @av: argument vector
 *
 * Return: integer
 */
int execute_pipe_mode(int fd, char *av)
{
	ssize_t bytesRead;
	char *tmp, **tokens, pipe[1024];
	int len = 0, count = 0, i = 0, res, wc_count = 0;

	bytesRead = read(fd, pipe, 1024);
	if (bytesRead < 0)
		return (1);
	pipe[bytesRead] = '\0';

	tokens = (char **)malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
		return (1);
	count = format_pipe(pipe, tokens);
	for (i = 0; i < count && tokens[i]; i++)
	{
		tmp = custom_strdup(tokens[i]);
		len = _strlen(tmp);
		wc_count = count_whitespace(tmp);
		if (wc_count == len || wc_count == -1)
			return (0);
		res = execute(tmp, len);
		if (res > 0)
		{
			show_errors(res, av, tmp, 1);
			return (res);
		}
		free(tmp);
		free(tokens[i]);
	}

	free(tokens);
	return (res);
}

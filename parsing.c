#include "main.h"

/**
 * check_for_executable - setup arguments
 * @args: pointer to array of strings
 * @str: input string
 * @path: path in global environment
 *
 * Return: void
 */
void check_for_executable(char **args, char *str, char *path)
{
	char *tmp;

	if (str != NULL)
	{
		tmp = get_path_from_environ(path, str);
		if (tmp != NULL)
		{
			_strcpy(args[0], tmp);
			free(tmp);
		}
		else
		{
			args[0] = NULL;
		}

		free(str);
	}
}

/**
 * setup_arguments - setup arguments
 * @args: pointer to array of strings
 * @input: input string
 * @delim: input delimeter
 *
 * Return: integer
 */
int setup_arguments(char **args, char *input, char *delim)
{
	char *s;
	char *str;
	struct stat sb;
	int i = 0;
	char *path;

	s = strtok(input, delim);
	str = NULL;
	if (s[0] == '/')
	{
		if (stat(s, &sb) == -1)
		{
			args[0] = NULL;
			return (0);
		}
	}
	else if (_strcmp(s, "exit") == 0)
	{
		args[0] = custom_strdup("exit");
		return (0);
	}
	else
	{
		str = custom_strdup(s);
	}

	for (i = 0; s != NULL; i++)
	{
		args[i] = custom_strdup(s);
		s = strtok(NULL, delim);
	}

	path = _get_env("PATH");
	check_for_executable(args, str, path);
	free(path);
	return (i);
}

/**
 * parse_input - splits the input
 * @input: input string
 * @len: length of string
 *
 * Return: array of strings
 */
char **parse_input(char *input, __attribute__((__unused__)) int len)
{
	char *delimeter;
	char **args;
	int c, i;

	c = count_token(input);
	if (c == -1)
		return (NULL);

	args = (char **)malloc((c + 1) * sizeof(*args));
	if (args == NULL)
		return (NULL);

	delimeter = custom_strdup(" \n\t\r");
	i = setup_arguments(args, input, delimeter);

	if (i > 0)
		args[i] = NULL;

	free(delimeter);
	return (args);
}

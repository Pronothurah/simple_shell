#include "main.h"

/**
 * find_executable - find path from $PATH directories
 * @input: input string
 * @token: current directory
 *
 * Return: pointer to a new allocated string or NULL
 */
char *find_executable(char *input, char *token)
{
	size_t dest_len;
	char *dest, *result;
	struct stat sb;

	dest_len = _strlen(token) + _strlen(input) + 2;
	dest = (char *)malloc(dest_len);

	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}

	_strcpy(dest, token);
	if (dest[_strlen(dest) - 1] != '/')
		_strcat(dest, "/");

	_strcat(dest, input);
	if (stat(dest, &sb) != -1)
	{
		result = (char *)malloc(sizeof(char) * _strlen(dest) + 1);
		if (result == NULL)
		{
			free(result);
			return (NULL);
		}

		_strcpy(result, dest);
	}

	free(dest);
	return (result);
}

/**
 * get_path_from_environ - gets path from global env
 * @path: path to the global env variable
 * @s: input string
 *
 * Return: pointer to path
 */
char *get_path_from_environ(const char *path, const char *s)
{
	char *s1;
	char *copy_of_s;
	char *p;
	char *result;

	if (path == NULL || path[0] == '\0')
	{
		return (NULL);
	}

	p = custom_strdup(path);
	copy_of_s = custom_strdup(s);
	s1 = strtok(p, ":");
	result = NULL;
	while (s1 != NULL)
	{
		result = find_executable(copy_of_s, s1);
		s1 = strtok(NULL, ":");
	}

	free(p);
	free(copy_of_s);

	return (result);
}

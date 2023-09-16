#include "main.h"

int count_token(char *input, int len)
{
	char *copy;
	char *s;
	int n = 0;

	copy = malloc(sizeof(char) * len);
	if (copy == NULL)
		return (-1);

	strcpy(copy, input);
	s = strtok(copy, " \n");

	while (s)
	{
		n++;
		s = strtok(NULL, " \n");
	}

	n++;
	free(copy);

	return (n);
}

char **parse_input(char *input, char *p, int len)
{
	char *s;
	char *tmp = NULL;
	char *str;
	int i;
	char **args;
	int c;
	struct stat sb;

	c = count_token(input, len);
	if (c == -1)
		return (NULL);

	args = (char **)malloc(c * sizeof(*args));
	if (args == NULL)
		return (NULL);

	s = strtok(input, " \n");
	str = malloc(sizeof(char) * strlen(s));
	if (str == NULL)
	{
		free(str);
	}

	if (s[0] == '/')
	{
		if (stat(s, &sb) == -1)
		{
			args[0] = malloc(sizeof(char) * strlen(s));
			args[0] = NULL;

			return (args);
		}

		str = NULL;
	}
	else if (strcmp(s, "exit") == 0)
	{
		args[0] = malloc(sizeof(char) * strlen(s));
		args[0] = "exit";

		return (args);
	}
	else
	{
		strcpy(str, s);
	}

	for (i = 0; s != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * strlen(s));
		strcpy(args[i], s);
		s = strtok(NULL, " \n");
	}

	if (str != NULL)
	{
		tmp = get_path_from_environ(p, str);
		if (tmp != NULL)
		{
			strcpy(args[0], tmp);
			free(tmp);
		}

		free(str);
	}

	args[i] = NULL;

	return (args);
}

char *get_path_from_environ(const char *path, const char *s)
{
	char *s1;
	char *copy_of_s;
	char *p;
	struct stat sb;
	char *dest;
	char *result;

	p = malloc(sizeof(char) * strlen(path));
	copy_of_s = malloc(sizeof(char) * strlen(s));
	if (path == NULL || path[0] == '\0' || p == NULL || copy_of_s == NULL)
	{
		return (NULL);
	}

	strcpy(p, path);
	strcpy(copy_of_s, s);
	s1 = strtok(p, ":");
	while (s1 != NULL)
	{
		size_t dest_len = strlen(s1) + strlen(copy_of_s) + 2;
		dest = (char *)malloc(dest_len);
		if (dest == NULL)
		{
			free(dest);
			continue;
		}

		strcpy(dest, s1);
		if (dest[strlen(dest) - 1] != '/')
			strcat(dest, "/");

		strcat(dest, copy_of_s);
		if (stat(dest, &sb) != -1)
		{
			result = (char *)malloc(sizeof(char) * strlen(dest));
			if (result == NULL)
			{
				free(result);
				continue;
			}

			strcpy(result, dest);
		}

		free(dest);
		s1 = strtok(NULL, ":");
	}

	free(p);
	free(copy_of_s);

	return (result);
}

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main()
{
	char *input;
	char **args;
	size_t len = 0;
	pid_t child_pid;
	int r;
	char *path = _get_env("PATH");

	while (1)
	{
		printf("($) ");
		r = getline(&input, &len, stdin);
		if (r == -1)
		{
			printf("\n");
			break;
		}

		args = parse_input(input, path, r);
		if (args[0] == NULL)
		{
			perror("No such file or directory\n");
		}
		else if (strcmp(args[0], "exit") == 0)
		{
			exit(0);
		}
		else
		{
			child_pid = fork();
			if (child_pid == -1)
				perror("Error:");

			if (child_pid == 0)
			{
				r = execve(args[0], args, __environ);

				if (r == -1)
				{
					perror("No such file or directory\n");
				}
			}
			else
			{
				wait(NULL);
			}
		}
	}

	free(input);
	free(args);

	return (0);
}
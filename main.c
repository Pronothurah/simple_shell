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
	int i;
	char **args;
	int c;

	(void)p;

	c = count_token(input, len);
	if (c == -1)
		return (NULL);

	args = (char **)malloc(c * sizeof(*args));
	if (args == NULL)
		return (NULL);

	s = strtok(input, " \n");
	for (i = 0; s != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * strlen(s));
		strcpy(args[i], s);

		s = strtok(NULL, " \n");
	}

	args[i] = NULL;

	return (args);
}

char *get_path_from_environ(char *path, char *s)
{
	char *s1;
	char *p;
	struct stat sb;
	int r;
	char *dest;

	p = malloc(sizeof(char) * strlen(path));
	if (p == NULL)
		return (NULL);

	strcpy(p, path);
	s1 = strtok(p, ":");
	while (s1)
	{
		dest = malloc(sizeof(char) * strlen(s1) + 1);
		if (dest == NULL)
			break;

		strcpy(dest, s1);
		if (dest[strlen(dest) - 1] != '/')
			strcat(dest, "/");
		strcat(dest, s);
		r = stat(dest, &sb);

		if (r != -1)
		{
			free(p);
			return (dest);
		}

		s1 = strtok(NULL, ":");
		free(dest);
	}

	free(p);

	return (NULL);
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
			printf("No such file or directory\n");
		}
		else
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
			}

			if (child_pid == 0)
			{
				r = execve(args[0], args, __environ);

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
	}

	free(input);
	free(args);

	return (0);
}
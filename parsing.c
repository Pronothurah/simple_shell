#include "main.h"

char **parse_input(char *input, char *p, __attribute__((__unused__)) int len)
{
	char *s;
	char *tmp = NULL;
	char *str;
	char *delimeter;
	int i;
	char **args;
	int c;
	struct stat sb;

	c = count_token(input);
	if (c == -1)
		return (NULL);

	args = (char **)malloc((c + 1) * sizeof(*args));
	if (args == NULL)
		return (NULL);

	delimeter = custom_strdup(" \n\t\r");
	s = strtok(input, delimeter);
	str = NULL;
	if (s[0] == '/')
	{
		if (stat(s, &sb) == -1)
		{
			args[0] = NULL;
			return (args);
		}
	}
	else if (strcmp(s, "exit") == 0)
	{
		args[0] = custom_strdup("exit");
		return (args);
	}
	else
	{
		str = custom_strdup(s);
	}

	for (i = 0; s != NULL; i++)
	{
		args[i] = custom_strdup(s);
		s = strtok(NULL, delimeter);
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
	free(delimeter);

	return (args);
}

#include "main.h"

char *_get_env(const char *name)
{
	int i;

	for (i = 0; __environ[i] != NULL; i++)
	{
		char *env_var = custom_strdup(__environ[i]);
		char *env_name = strtok(env_var, "=");
		char *env_value = strtok(NULL, "=");

		if (env_name != NULL && env_value != NULL && strcmp(env_name, name) == 0)
		{
			char *result = (char *)malloc(strlen(env_value) + 1);
			if (result != NULL)
			{
				strcpy(result, env_value);
				free(env_var);
				return (result);
			}
			else
			{
				free(result);
				free(env_var);
				return (NULL);
			}
		}

		free(env_var);
	}

	return (NULL);
}

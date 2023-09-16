#include "main.h"

char *_get_env(const char *name)
{
  char **e;
  char *s;
  char *copy;
  int i;
  int j;

  e = (char **)malloc(1024 * sizeof(*e));

  for (i = 0; __environ[i] != NULL; i++)
  {
    e[i] = malloc(sizeof(char) * strlen(__environ[i]));
    e[i] = __environ[i];
  }

  for (i = 0; e[i] != NULL; i++)
  {
    copy = malloc(sizeof(char) * strlen(e[i]));

    strcpy(copy, e[i]);
    s = strtok(copy, "=");
    j = strcmp(s, name);

    if (j == 0)
    {
      return (strtok(NULL, "="));
    }
  }

  free(e);

  return (NULL);
}
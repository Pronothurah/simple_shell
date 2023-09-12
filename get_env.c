#include "main.h"

char *_get_env(const char *name)
{
  char **e;
  char *s;
  int i;
  int j;

  e = __environ;

  for (i = 0; e[i] != NULL; i++)
  {
    s = strtok(e[i], "=");
    j = strcmp(s, name);

    if (j == 0)
    {
      return (strtok(NULL, "="));
    }
  }

  return (NULL);
}
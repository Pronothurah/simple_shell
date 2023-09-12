#include "main.h"

char **_get_directory_in_path(char *path)
{
  char *s;
  char **r;
  int i = 0;

  r = malloc(sizeof(char) * strlen(path));
  if (r == NULL)
    exit(-1);

  s = strtok(path, ":");
  while (s != NULL)
  {
    r[i] = s;
    s = strtok(NULL, ":");
    i++;
  }

  return (r);
}

void _print_directory_in_path(char **directories)
{
  int i;

  printf("\n");

  for (i = 0; directories[i]; i++)
    printf("%s\n", directories[i]);

  free(directories);
}
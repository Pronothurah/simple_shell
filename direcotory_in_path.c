#include "main.h"

void _print_directory_in_path(char *path)
{
  char *s;

  printf("\n");

  s = strtok(path, ":");

  while (s != NULL)
  {
    printf("%s\n", s);
    s = strtok(NULL, ":");
  }
}
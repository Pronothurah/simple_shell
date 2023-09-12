#include "main.h"

void _print_environ(void)
{
  char **e;
  int i;

  e = __environ;

  for (i = 0; e[i] != NULL; i++)
  {
    printf("%s\n", e[i]);
  }
}
#include "main.h"

void _print_line(void)
{
  char *s;
  size_t len = 0;
  int r;

  s = malloc(sizeof(char) * 50);
  if (s == NULL)
    free(s);

  printf("\n$ ");
  r = getline(&s, &len, stdin);

  if (r != -1)
    printf("%s", s);

  free(s);
}
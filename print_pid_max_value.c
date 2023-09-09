#include "main.h"

void _print_process_id_maximum_value(char *str)
{
  int o;
  int r;
  char s[100];

  o = open(str, O_RDONLY);
  r = read(o, s, 100);

  if (r != -1)
    printf("%s", s);

  close(o);
}
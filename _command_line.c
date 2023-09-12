#include "main.h"

void _print_command_line_to_av(char *text, char *delimeter)
{
  char *s;

  s = strtok(text, delimeter);
  while (s)
  {
    printf("%s\n", s);
    s = strtok(NULL, delimeter);
  }
}
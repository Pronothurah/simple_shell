#include "main.h"

void _av(char **va)
{
  int i;

  for (i = 1; va[i] != NULL; i++)
    printf("%s ", va[i]);
}
#include "main.h"

void _find_path(__attribute__((__unused__)) char *path)
{
  struct stat s;
  int i;

  i = stat(path, &s);

  if (i == 0)
    printf("found %ld\n", s.st_size);
  else
    printf("found 0\n");
}

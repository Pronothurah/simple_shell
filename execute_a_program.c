#include "main.h"

void _execute_a_program(void)
{
  char *a[] = {"/bin/ls", "-l", "/tmp", NULL};
  int r;
  pid_t my_pid;
  pid_t child_pid;
  int i;
  int status;

  printf("\n");

  for (i = 0; i < 5; i++)
  {

    if (child_pid == -1)
    {
      perror("Error:");
      exit(-1);
    }

    if (child_pid == 0)
    {
      my_pid = getpid();
      printf("Parent: (%u), Child: (%u)\n", _getppid(), my_pid);
      r = execve(a[0], a, NULL);

      if (r == -1)
        exit(-1);
      sleep(1);
    }
    else
    {
      wait(&status);
      child_pid = fork();
    }
  }
}

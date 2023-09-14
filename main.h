#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct list
{
  char *data;
  struct list *next;
} list_t;

int _putchar(char c);
pid_t _getppid(void);
void _print_process_id_maximum_value(char *str);
void _av(char **va);
void _print_line(void);
void _print_command_line_to_av(char *text, char *delimeter);
void _execute_a_program(void);
void _find_path(char *path);
void _print_environ(void);
char *_get_env(const char *name);
char **_get_directory_in_path(char *);
void _print_directory_in_path(char **);
list_t *create_linkedlist_from_path_directory(char **);
void _print_linkedlist(list_t *);
char **parse_input(char *input, char *path, int len);
char *get_path_from_environ(char *path, char *s);
int count_token(char *input, int len);

#endif /* MAIN_H */

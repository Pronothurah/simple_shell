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

int _putchar(char c);
pid_t _getppid(void);
void _print_process_id_maximum_value(char *str);
void _av(char **va);
void _print_line(void);
void _print_command_line_to_av(char *text, char *delimeter);
void _execute_a_program(void);
void _find_path(char *path);

#endif /* MAIN_H */

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
#include <signal.h>
#include <errno.h>

char *_get_env(const char *name);
int _putchar(char c);
int _strlen(const char *str);
void _print(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char **parse_input(char *input, char *path, int len);
int setup_arguments(char **args, char *input, char *delim, char *path);
void check_for_executable(char **args, char *str, char *path);
char *get_path_from_environ(const char *path, const char *s);
char *find_executable(char *path, char *input);
int count_token(char *input);
char *custom_strdup(const char *str);
void catch_ctrlc(int);
void free_args(char **args);
void __exit(char *input, char *path, char **args);
int execute(char *input, char *path, int length);
int execute_pipe_mode(int fd, char *path);

#endif /* MAIN_H */

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define CHAR_SIZE 128

int _putchar(char c);
int _strlen(const char *str);
void _print(const char* str);
void shell_prompt(void);

#endif /* SHELL_H */

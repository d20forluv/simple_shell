#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>

extern char **environ;
int _putchar(char c);
int _puts(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *find_exec(char *s);
int check_command(char *s);
int _strlen(char *s);
char **tokenizer(char *line, char *d);
void hsh(char *);
void frees(char **);
char *find_path(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);

#endif

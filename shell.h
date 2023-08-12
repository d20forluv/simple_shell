#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#define EXIT_CODE 1080

extern char **environ;
/**
 * struct builtin_command - Short description
 * @name: First member
 * @function: Second member
 *
 * Description: Longer description
 */
struct builtin_command
{
        char *name;
        int (*function)(char **array_of_tokens);
};
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
int exits(char **lineptr, size_t *n);
int forks(char **args, char *str);
void place(void);
int swap(char **arg);
void exit_bi(char *str);
void print_env(char **environ);
int built_in(char **args);
char *get_path_variable();
char *search_file_in_path(char *file_name, char *path_var);
void free_token_array(char **tokens, int num_tokens);
int is_delim(char c, char *delim);
int env_builtin(char **args __attribute__((unused)));
int exit_builtin(char **str);
int getlines(char **lineptr, size_t *n);
int is_builtin(char **array_of_tokens);
int builtin_handler(char **array_of_tokens);
#endif

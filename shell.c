#include "shell.h"

/**
 * exit_bi - check if a string is "exit"
 * @str: string to compare
 *
 * Return: none
 */
void exit_bi(char *str)
{
	if (_strcmp(str, "exit") == 0)
		exit(0);
}

/**
 * print_env - print all enviroment variables, each on a new line
 * @environ: global variable environ
 *
 * Return: none
 */
void print_env(char **environ)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
 * built_in - exit if the string is "exit"
 * @args: pointer conatining the pointer to compare
 *
 * Return: 1 on success, -1 on failure
 */
int built_in(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		exit_bi(args[0]);
		/*frees(args);*/
		return (1);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_env(environ);
		/*frees(args);*/
		return (1);
	}
	return (-1);
}

/**
 * hsh - the shell mai function
 * @str: name of executable
 *
 * Return: none
 */
void hsh(char *str)
{
	int i, s, b;
	size_t n = 0;
	char *lineptr = NULL, **token = NULL;

	while (1)
	{
		place();
		if (exits(&lineptr, &n) == -1)
		{
			exit(0);
		}
		token = tokenizer(lineptr, " \n");
		if (token[0] == NULL)
		{
			frees(token);
			continue;
		}

		b = built_in(token);
		if (b == 1)
		{
			frees(token);
			continue;
		}
		s = swap(token);
		if (s == -1)
		{
			frees(token);
			continue;
		}
		i = forks(token, str);
		if (i == 0)
		{
			frees(token);
			continue;
		}
	}
	frees(token);
}

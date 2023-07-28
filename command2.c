#include "shell.h"

/**
 * exits - read a line input from a user
 * @lineptr: pointer to store the address of the line read
 * @n: pointer to store the number of bytes read
 *
 * Return: 1 on success, -1 on failure
 */
int exits(char **lineptr, size_t *n)
{
	int read;

	read = getline(lineptr, n, stdin);
	if (read == -1)
	{
		if (errno == 0)
			return (-1);
		perror("getline");
		return (-1);
	}
	return (1);
}

/**
 * forks - create a child process to execute a command
 * @args: pointers to array to pass to execve
 * @str: argument to pass in case of error
 *
 * Return: 0 on failure, 1 on success
 */
int forks(char **args, char *str)
{
	int i, status;

	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}

	if (pid == 0)
	{
		i = execve(args[0], args, environ);
		if (i == -1)
		{
			perror(str);
			return (0);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}

/**
 * place - print a '$ ' if in interactive mode
 *
 * Return: none
 */
void place(void)
{
	if (isatty(0))
		_puts("$ ");
}

/**
 * swap - swap the value of two pointer
 * @arg: pointer that contains pointer to swap
 *
 * Return: 1 on success, -1 on failure
 */
int swap(char **arg)
{
	char *s = find_path(arg[0]);

	if (s == NULL)
	{
		perror("find_path");
		return (-1);
	}

	if (check_command(s) == 0)
	{
		perror("NOT FOUND");
		free(s);
		return (-1);
	}

	free(arg[0]);
	arg[0] = s;
	return (1);
}

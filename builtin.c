#include "shell.h"

/**
 * builtin_handler - description
 *
 * @array_of_tokens: description
 *
 * Return: 1 if success 0 if failure
 */
int builtin_handler(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", env_builtin},
		{"exit", exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
	{
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (builtins[builtin_index].function(array_of_tokens));
	}
	return (0);
}

/**
 * is_builtin - description
 *
 * @array_of_tokens: decrtipyion
 *
 * Return: 1 if success 0 if failure
 */
int is_builtin(char **array_of_tokens)
{
	int builtin_index;
	const struct builtin_command builtins[] = {
		{"env", env_builtin},
		{"exit", exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (builtin_index = 0; builtins[builtin_index].name != NULL;
			builtin_index++)
		if (strcmp(array_of_tokens[0],
					builtins[builtin_index].name) == 0)
			return (1);
	return (0);
}

/**
 * getlines - decription
 * @lineptr: line
 * @n: integer
 *
 * Return: -1 or 1
 */
int getlines(char **lineptr, size_t *n)
{
	int read = getline(lineptr, n, stdin);

	if (read == -1 && errno == 0)
	{
		if (errno == 0)
			return (-1);
		return (-1);
	}
	return (1);
}

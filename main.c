#include "shell.h"

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

int exit_builtin(char **str)
{
	if (str[1] != NULL)
		exit(atoi(str[1]));
	else
		return (EXIT_CODE);
}

int env_builtin(char **args __attribute__((unused)))
{
 	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}

/**
 * main - main file
 * @ac: Number of arguments passed
 * @argv: arrays of pointers to the argument
 *
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char *argv[])
{
	int read;
	size_t n = 0;
	char *lineptr = NULL, **token;
	while (1)        
	{
		place();
		read = getline(&lineptr, &n, stdin);
		if (read == -1)
		{
			break;
		}
		token = tokenizer(lineptr, " \n");
		if (!(*token))
		{
			free(lineptr);
			frees(token);
			continue;
		}
		else
		{
			if (is_builtin(token))
			{
				if (builtin_handler(token) == EXIT_CODE)
				{
					frees(token);
					free(lineptr);
					exit(0);
				}
			}
			else
			{
				swap(token);
				forks(token, argv[0]);
			}
		}
		frees(token);
		free(lineptr);
		lineptr = NULL;
	}
	free(lineptr);
	return (0);
}

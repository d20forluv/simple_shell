#include "shell.h"

/**
 * exit_builtin - check if a string is "exit"
 * @array_of_tokens: string to compare
 *
 * Return: int
 */
int exit_builtin(char **array_of_tokens)
{
	if (array_of_tokens[1] != NULL)
	{
		frees(array_of_tokens);
		exit(atoi(array_of_tokens[1]));
	}
	else
		return (EXIT_CODE);
}

/**
 * env_builtin - print all enviroment variables, each on a new line
 * @args: global variable environ
 *
 * Return: none
 */
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
 * free_main - free array of tokens in the main function
 * @array_of_tokens: tokenized string
 * @input: string
 *
 * Return: void
 */
void free_main(char **array_of_tokens, char *input)
{
	int index;

	for (index = 0; array_of_tokens[index]; index++)
		free(array_of_tokens[index]);
	free(array_of_tokens);
	free(input);
}

/**
 * hsh - the shell mai function
 * @str: name of executable
 *
 * Return: none
 */
void hsh(char *str)
{
	int status = 0;
	size_t n = 0;
	char *lineptr = NULL, **tokens;

	while (1)
	{
		place();
		if (getlines(&lineptr, &n) == 1)
		{
			if ((tokens = tokenizer(lineptr, " \n")) != NULL)
			{
				if (is_builtin(tokens))
				{
					if (builtin_handler(tokens) == EXIT_CODE)
					{
						free_main(tokens, lineptr);
						exit(0);
					}}
				else
				{
					if ((status = forks(tokens, str)) == 0)
						;
					else
					{
						free_main(tokens, lineptr);
						exit(status);
					}}}
			else
				exit(status);
		}
		else
		{
			free(lineptr);
			exit(status);
		}
		free_main(tokens, lineptr);
		lineptr = NULL;
	}
}

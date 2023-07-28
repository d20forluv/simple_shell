#include "shell.h"

/**
 * check_command - checks if a file is an executable
 * @s: file name to check
 *
 * Return: 1 if true, 0 otherwise
 */
int check_command(char *s)
{
	if ((access(s, X_OK)) == 0)
		return (1);
	return (0);
}

/**
 * find_path - finds the full path of a file
 * @s: file name to find
 *
 * Return: The file path on success, the original string on failure
 */
char *find_path(char *s)
{
	char *path_var = get_path_variable();

	if (path_var == NULL)
		return (NULL);

	char *path = search_file_in_path(s, path_var);

	free(path_var);
	return (path);
}

/**
 * get_path_variable - retrieves the PATH environment variable
 *
 * Return: The PATH variable on success, NULL on failure
 */
char *get_path_variable()
{
	int i = 0;

	while (environ[i])
	{
		char *env_var = strdup(environ[i]);

		if (env_var == NULL)
		{
			perror("strdup");
			return (NULL);
		}

		char *token = strtok(env_var, "=");

		if (_strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			char *path_var = strdup(token);

			free(env_var);
			return (path_var);
		}

		free(env_var);
		i++;
	}

	return (NULL);
}

/**
 * search_file_in_path - searches for a file in directories listed
 * @file_name: file name to search for
 * @path_var: The PATH variable
 *
 * Return: The file path on success, NULL on failure
 */
char *search_file_in_path(char *file_name, char *path_var)
{
	char *token = strtok(path_var, ":");

	while (token != NULL)
	{
		char *full_path = malloc(_strlen(token) + _strlen(file_name) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}

		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, file_name);

		if (check_file_exists(full_path))
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * tokenizer - Tokenizes a string into tokens using a delimiter.
 * If delim is not present/provided, then the delimiter is ' '
 *
 * @line: Input string (line) to be tokenized.
 * @delim: The character used as the delimiter for tokenization: ' '.
 *
 * Return: An array of pointers to each token (char**).
 * The last element of the array will be set to NULL.
 */
char **tokenizer(char *line, char *delim)
{
	if (line == NULL)
		return (NULL);

	int num_tokens = 0, token_size = 2;

	char **tokens = (char **)malloc(token_size * sizeof(char *));

	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	char *token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[num_tokens] = strdup(token);
		if (tokens[num_tokens] == NULL)
		{
			perror("strdup");
			free_token_array(tokens, num_tokens);
			return (NULL);
		}
		num_tokens++;
		if (num_tokens >= token_size)
		{
			token_size *= 2;
			tokens = (char **)realloc(tokens, token_size * sizeof(char *));
			if (tokens == NULL)
			{
				perror("realloc");
				free_token_array(tokens, num_tokens);
				return (NULL);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[num_tokens] = NULL;
	return (tokens);
}

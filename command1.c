#include "shell.h"

/**
 * check_command - checks if a file is an execuatble
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
	struct dirent *entry;
	DIR *dirp;
	int i = 0;
	char *token, *path = NULL, *env_var;

	while (environ[i])
	{
		env_var = malloc(_strlen(environ[i]) + 1);
		strcpy(env_var, environ[i]);
		token = strtok(env_var, "=");
		if (_strcmp(token, "PATH") == 0)
		{
			while ((token = strtok(NULL, ":")) != NULL)
			{
				dirp = opendir(token);
				if (dirp == NULL)
				{
					free(env_var);
					perror("opendir");
				}
				while ((entry = readdir(dirp)) != NULL)
				{
					if (_strcmp(s, entry->d_name) == 0)
					{
						path = malloc(sizeof(char) * 1024);
						_strcpy(path, token);
						_strcat(path, "/");
						_strcat(path, entry->d_name);
						closedir(dirp);
						free(env_var);
						return (path);
					}
				}
				closedir(dirp);
			}
		}
		free(env_var);
		i++;
	}
	return (s);
}

/**
 * tokenizer - This will Tokenizes a string into tokens using a delimiter.
 * If delim is not present/provided, then delimiter is ' '
 *
 * @line: This will input string (line) to be tokenized.
 * @delim: This is the character used as delimiter for tokenization: ' '.
 *
 * Return: Return will return an array of pointers to each token (char**).
 * last element of the array will be set to NULL.
 */
char **tokenizer(char *line, char *delim)
{
	char *token, **tokens;
	int num_tokens = 0, token_size = 2;

	if (line == NULL)
		return (NULL);

	tokens = NULL;
	tokens = (char **)malloc(token_size * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[num_tokens++] = token;
		if (num_tokens >= token_size)
		{
			token_size *= 2;
			tokens = (char **)realloc(tokens, token_size * sizeof(char *));
			if (tokens == NULL)
			{
				perror("realloc");
				return (NULL);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[num_tokens] = NULL;
	return (tokens);
}

/**
 * frees - frees up a 2D array
 * @str: The array to free
 *
 * Return: none
 */
void frees(char **str)
{
	int i = 0;

	if (str != NULL)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

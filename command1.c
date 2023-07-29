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
 * @str: This will input string (line) to be tokenized.
 * @d: This is the character used as delimiter for tokenization: ' '.
 *
 * Return: Return will return an array of pointers to each token (char**).
 * last element of the array will be set to NULL.
 */
char **tokenizer(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * is_delim - f...
 * @c: ..
 * @delim: ..
 *
 * Return: 1 on success, 0 on failure
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
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

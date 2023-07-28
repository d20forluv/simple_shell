#include "main.h"

/**
 * free_token_array - Frees the memory used by the token array.
 * @tokens: The token array.
 * @num_tokens: The number of tokens in the array.
 *
 * Return: none
 */
void free_token_array(char **tokens, int num_tokens)
{
	for (int i = 0; i < num_tokens; i++)
		free(tokens[i]);
	free(tokens);
}

}

/**
 * frees - frees up a 2D array
 * @str: The array to free
 *
 * Return: none
 */
void frees(char **str)
{
	if (str != NULL)
	{
		for (int i = 0; str[i] != NULL; i++)
			free(str[i]);
		free(str);
	}
}

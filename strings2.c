#include "shell.h"

/**
 * _strcpy - program that copies a character
 * @dest: pointer to the destination array where the content is to be copied.
 * @src: This is the string to be copied.
 * Return: return dest on success
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - function creates a duplicate of the string pointed to by string.
 * @str: the string value
 * Return: return ret on success
 */
char *_strdup(const char *str)
{
	int length = 0;

	char *ret;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	ret = (char *)malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	_strcpy(ret, (char *)(str - (length + 1)));

	return (ret);
}

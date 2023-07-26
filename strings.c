#include "shell.h"

/**
 * _putchar - program that prints formatted outpt
 * @c: the character c
 * Return: length of formated string on SUCCESS
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - program that allows for input of strings
 * @s: this is the string value
 * Return: return success 1
 */
int _puts(char *s)
{
	if (s == NULL || !*s)
		return (-1);
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	return (1);
}

/**
 * _strcat - function that concatenates string2 to string1, end with null
 * @dest: pointer to the destination array content is to be copied.
 * @src: This is the string to be copied.
 * Return: return dest on success
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - function copies string2, with ending null char, to string1
 * @s1: the first string@char: chararcter for string 1
 * @s1: the first string
 * @s2: the second string
 * Return: return s1 and s2 on success
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/**
 * _strlen - program that prints the lenght of string
 * @s: the required string
 * Return: return i on success
 */
int _strlen(char *s)
{
	int i;

	for (i = 0 ; s[i] != '\0' ; i++)
		;
	return (i);
}

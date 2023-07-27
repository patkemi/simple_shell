#include "shell_main.h"
/**
 * _strdup - function that duplicate a string
 * @str: input string
 * Return: returns the duplicate of the string
 */
char *_strdup(char *str)
{
	char *dup;
	size_t len = _strlen(str);
	size_t i = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	dup = (char *)malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
	{
		return (NULL);
	}
	else
	{
		while (i < len)
		{
			dup[i] = str[i];
			i++;
		}
	}
	dup[len] = '\0';

	return (dup);
}

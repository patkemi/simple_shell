#include "shell_main.h"
/**
 * _strlen - function that calculates the lengths of
 * a string
 * @str: the string to calculate its length
 * Return: returns the length of the string
 */
size_t _strlen(char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

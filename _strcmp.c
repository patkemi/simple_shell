#include "shell_main.h"
/**
 * _strcmp - function that compares two strings
 * @str1: compared string
 * @str2: string to compare
 * Return: return 0 if equal, 1 if its str1 is greater than str2
 * and -1 if str1 < str2.
 */
int _strcmp(char *str1, char *str2)
{
	size_t i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] > str2[i])
		{
			return (1);
		}
		else if (str1[i] < str2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

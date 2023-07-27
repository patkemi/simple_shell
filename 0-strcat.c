#include "shell_main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination file
 * @src: source file
 * Return: return a pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int len1 = 0;
	int len2 = 0;

	while (dest[len1] != '\0')
	{
		len1++;
	}
	while (src[len2] != '\0')
	{
		len2++;
	}

	for (; i < len2; i++)
	{
		dest[len1 + i] = src[i];
	}
	dest[len1 + i] = '\0';

	return (dest);
}

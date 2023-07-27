#include "shell_main.h"

/**
 * _strcpy - copy string from sorce to buffer
 * @dest: buffer to store the copied string
 * @src: source code
 * Return: return a pointer to dust
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

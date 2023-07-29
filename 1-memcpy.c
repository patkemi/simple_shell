#include "shell_main.h"

/**
 * _memcpy - function the copies memory area.
 * @dest: point to the memory area
 * @src: pointer to momory to be copied
 * @n: size to copy
 * Return: return pointer to the memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

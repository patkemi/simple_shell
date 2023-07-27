#include "shell_main.h"
/**
 * _itoa - function that converts iterger to a string
 * @n: integer to convert
 * Return: returns converted string
 */
char *_itoa(int n)
{
	unsigned int num1;
	int len = _get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (len + 1));

	if (!buffer)
	{
		return (NULL);
	}

	*(buffer + len) = '\0';
	if (n < 0)
	{
		num1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = n;
	}
	while (num1 > 0)
	{
		*(buffer + len) = (num1 % 10) + '0';
		num1 = num1 / 10;
		len--;
	}
	return (buffer);
}

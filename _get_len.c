#include "shell_main.h"
/**
 * _get_len - function that returns the length of a number
 * @num: parameter to check
 * Return: return the length.
 */
int _get_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 = num1 / 10;
	}
	return (len);
}

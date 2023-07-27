#include "shell_main.h"

/**
 * _atoi - function that convert string repesentation of an integer
 * tp an integer
 * @s: pointer to the string
 * Return: retrn integer values of string representative
 */
int _atoi(char *s)
{
	unsigned int result = 0;
	int sign = 1;
	int i = 0;
	int is_digit = 0;

	while (s[i])
	{
	if (s[i] == '-')
	{
		sign *= -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		is_digit = 1;
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	if (is_digit == 1)
	{
		break;
	}
	i++;
	}
	return (result * sign);
}

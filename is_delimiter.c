#include "shell_main.h"
/**
 * is_delimiter - function that checks if a character is a
 * delimiter.
 * @c: character to check
 * @delimiter: delimiter
 * Return: return 1 if success or 0 if otherwise.
 */
int is_delimiter(char c, const char *delimiter)
{
	int i = 0;

	while (delimiter[i] != '\0')
	{
		if (c == delimiter[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

#include "shell_main.h"
/**
 * is_delimiter - function that checks if a character is a delimiter
 * @ch: character to check.
 * @delimiter: delimiter to chaeck
 * Return: returns true if character is a delimeter or false if
 * otherwise.
 */
bool is_delimiter(char ch, const char *delimiter)
{
	while (*delimiter != '\0')
	{
		if (ch == *delimiter)
		{
			return (true);
		}
		delimiter++;
	}
	return (false);
}

/**
 * _strtok - function that tokenize a string;
 * @str: pointer to the string.
 * @delimiter: delimeter to token.
 * Return: returns a pointer to the tokenized string
 */
char *_strtok(char *str, const char *delimiter)
{
	static char *last_ptr;
	char *token_start;

	if (str == NULL)
	{
		str = last_ptr;
	}

	if (str == NULL || *str == '\0')
	{
		last_ptr = NULL;
		return (NULL);
	}
	token_start = (char *)str;

	while (*str != '\0' && !is_delimiter(*str, delimiter))
	{
		str++;
	}
	if (*str != '\0')
	{
		*str = '\0';
		last_ptr = str + 1;
	}
	else
	{
		last_ptr = NULL;
	}
	return (token_start);
}


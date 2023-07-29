#include "shell_main.h"
/**
 * num_tokens - function that checks the number of tokens in a string
 * @str: pointer to the string
 * @delimiter: delimiter to tokenize the string.
 * Return: returns the quantity of tokens in a string.
 */
int num_tokens(char *str, const char *delimiter)
{
	int tokens_num = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_delimiter(str[i], delimiter))
		{
			tokens_num++;
		}
	}
	return (tokens_num);
}

#include "shell_main.h"
/**
 * tokeniz_string - function that tokenize a string
 * @str: string parameter to tokenize
 * @delimiter: delimiter
 * Return: return array of tokens
 */
char **tokeniz_string(char *str, const char *delimiter)
{
	char **tokens, *end;
	int index = 0, token_length = 0, total_tokens = 0;

	if (str == NULL || delimiter == NULL)
	{
		return (NULL);
	}
	total_tokens = num_tokens(str, delimiter);
	tokens = (char **)malloc((total_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		return (NULL);
	}
	while (*str != '\0')
	{
		while (*str != '\0' && is_delimiter(*str, delimiter))
		{
			str++;
		}
		if (*str == '\0')
			break;
		end = str;
		while (*end != '\0' && !is_delimiter(*end, delimiter))
		{
			end++;
		}
		token_length = end - str;
		tokens[index] = (char *)malloc((token_length + 1) * sizeof(char));
		if (tokens[index] == NULL)
		{
			free_string(tokens, index);
			return (NULL);
		}
		_memcpy(tokens[index], str, token_length);
		tokens[index][token_length] = '\0';
		index++;
		str = end;
	}
	tokens[index] = NULL;
	return (tokens);
}

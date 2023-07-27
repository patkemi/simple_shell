#include "shell_main.h"
/**
 * tokeniz - function that splits strings into tokens
 * @str: the string to br passed
 * @delimiter: delimiter character to tokenize.
 * Return: returns an array of tokens
 */
char **tokeniz(char *str, const char *delimiter)
{
	char **tokens = NULL, *new_str, *token;
	int count = 0;

	new_str = _strdup(str);

	if (!new_str)
	{
		return (NULL);
	}
	token = strtok(new_str, delimiter);

	while (token != NULL)
	{
		tokens = (char **)realloc(tokens, (count + 1) * (sizeof(char *)));
		if (!tokens)
		{
			free(new_str);
			return (NULL);
		}
		tokens[count] = _strdup(token);
	if (!tokens[count])
	{
		return (NULL);
	}
	count++;
	token = strtok(NULL, delimiter);
	}
	tokens = (char **)realloc(tokens, (count + 1) * sizeof(char *));
	if (!tokens)
	{
		free(new_str);
		return (NULL);
	}
	tokens[count] = NULL;
	free(new_str);

	return (tokens);
}

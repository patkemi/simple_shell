#include "shell_main.h"
/**
 * copy_tokens - function that copies a token
 * @tokens: pointer to an array of tokens
 * Return: returns the copied tokens
 */
char **copy_tokens(char **tokens)
{
	int i;
	char **copy = NULL;

	for (i = 0; tokens[i] != NULL; i++)
	{
		;
	}
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	for (i = 0; tokens[i] != NULL; i++)
	{
		copy[i] = _strdup(tokens[i]);
		if (!copy[i])
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
	}
	copy[i] = NULL;
	return (copy);
}

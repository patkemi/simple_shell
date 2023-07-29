#include "shell_main.h"
/**
 * free_string - function that frees a string
 * @tokens: string tokens
 * @num_tokens: number of tokens
 */
void free_string(char **tokens, int num_tokens)
{
	int i;

	for (i = 0; i < num_tokens; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

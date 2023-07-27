#include "shell_main.h"
/**
 * free_tokens - function that free dynamic allocated memorie
 * @tokens: memory spaces allocated
 *
 */
void free_tokens(char **tokens)
{
	char **current_tokens;

	current_tokens = tokens;
	while (*current_tokens)
	{
		free(*current_tokens);
		current_tokens++;
	}
	free(tokens);
}

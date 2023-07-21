#include "shell_main.h"

/**
 * parse_the_user_input - parse user input into tokens.
 *
 * Arguments: @input: The user input string.
 *
 * Returns: An array of dynamically allocated strings containing the tokens.
 * The caller is responsible for freeing the allocated memory.
 */
char **parse_user_input(char *input)
{
	char **tokens;
	char *batch;
	int i = 0;

	tokens = malloc(sizeof(char *) * BUFFER_SIZE);

	if (!tokens)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	batch = strtok(input, TOKEN_DELIMITERS);


	while (batch)
	{
		tokens[i] = strdup(batch);
		i++;
		batch = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[i] = NULL;

	return (tokens);
}

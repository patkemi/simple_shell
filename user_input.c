#include "shell_main.h"
/**
 * user_input - Reads user input from stdin.
 *
 * Return: returns dynamically allocated string containing the user input.
 * The caller is responsible for freeing the allocated memory.
 */
char *user_input(void)
{
	size_t length;
	char *input;

	input = malloc(sizeof(char) * BUFFER_SIZE);

	if (!input)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	write(1, "#simple_shell$ ", 15);
	if (fgets(input, BUFFER_SIZE, stdin) == NULL)
	{
		free(input);
		return (NULL);
	}
	length = strlen(input);

	if (input[length - 1] == '\n')
	input[length - 1] = '\0';

	return (input);
}

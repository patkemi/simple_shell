#include "shell_main.h"
/**
 * user_input - function that accepts input from user.
 * @shell: pointer to the struct.
 * Return: return string input.
 */
char *user_input(simple_shell *shell)
{
	size_t len = 0;
	char *input = NULL;
	int input_size;

	write(1, "#simple_shell$ ", 15);
	if ((getline(&input, &len, stdin) == -1))
	{
		if (feof(stdin))
		{
			free(input);
			return (NULL);
		}
		else
		{
			perror("Error reading input");
			free(input);
			return (NULL);
		}
	}
	input_size = _strlen(input);

	if (input != NULL && input[input_size - 1] == '\n')
	{
		input[input_size - 1] = '\0';
	}
	shell->input = _strdup(input);

	return (shell->input);
}

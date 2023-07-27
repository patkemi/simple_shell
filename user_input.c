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
	ssize_t text_read;

	if (isatty(STDIN_FILENO))
	{
		write(1, "#simple_shell$ ", 15);
	}
	text_read = getline(&input, &len, stdin);
	if (text_read == 1)
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
		}
	}
	else if (text_read > 1 && input[text_read - 1] == '\n')
	{
		input[text_read - 1] = '\0';
	}
	shell->input = input;
	return (input);
}

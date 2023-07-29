#include "shell_main.h"
/**
 * user_input - function that accepts input from user.
 * @shell: pointer to the struct.
 * Return: return string input.
 */
char *user_input(simple_shell *shell)
{
	size_t len = 0, input_len;
	char *input = NULL;
	ssize_t text_read;

	write(1, "#simple_shell$ ", 15);
	text_read = getline(&input, &len, stdin);
	if (text_read == -1)
	{
		free(input);
		return (NULL);
	}
	input_len = _strlen(input);
	if (input_len > 0 && input[input_len - 1] == '\n')
	{
		input[input_len - 1] = '\0';
	}
	shell->input = _strdup(input);
	return (input);
}

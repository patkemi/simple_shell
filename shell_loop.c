#include "shell_main.h"
/**
 * shell_loop - function that loops shell
 * @av: argument vectors
 * @shell: pointer to the shell
 */
void shell_loop(char *av[], simple_shell *shell)
{
	char *input, *args[] = {NULL, NULL};

	while (1)
	{
		input = user_input(shell);
		if (!input)
		{
			free(input);
			break;
		}
		else
		{
			args[0] = input;
			execute_command(av, args, shell);
		}
		free(input);
	}
}

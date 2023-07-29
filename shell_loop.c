#include "shell_main.h"
/**
 * shell_loop - function that loops shell
 * @av: argument vectors
 * @shell: pointer to the shell
 */
void shell_loop(char *av[], simple_shell *shell)
{
	char *input, **args = NULL;

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
			args = (char **)malloc(2 * sizeof(char *));

			args[0] = input;
			args[1] = NULL;
			execute_command(av, args, shell);
			free(args[0]);
			free(args);
		}
	}
}

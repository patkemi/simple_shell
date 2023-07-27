#include "shell_main.h"
/**
 * shell_loop - function that loops shell
 * @av: argument vectors
 * @shell: pointer to the shell
 */
void shell_loop(char *av[], simple_shell *shell)
{
	char *input, *command;
	char **tokens = NULL;
	int (*f)(simple_shell *shell, char **args) = NULL, status, i;

	while (1)
	{
		input = user_input(shell);
		if (input == NULL)
		{
			continue;
		}
		tokens = tokeniz(input, ";");

		if (tokens != NULL)
		{
			i = 0;
			while (tokens[i] != NULL)
			{
				shell->args = tokeniz(tokens[i], " \t\n");
				if (shell->args != NULL && shell->args[0] != NULL)
				{
					command = shell->args[0];
					f = execute_builtin(command)
					if (f != NULL)
					{
						status = f(shell, shell->args);
					if (status == 0)
					{
						free_args(shell->args);
					}
					}
					else
						execute_command(av, shell->args, shell);
				}
				i++;
			}
		}
		free_tokens(tokens);
	}
}

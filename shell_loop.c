#include "shell_main.h"
/**
*pat_shell_loop - function that loop shell
*
*/
void pat_shell_loop(void)
{
	char *input;
	char **tokens;
	int status = 1;
	int i;

	while (status)
	{
		input = user_input();
		tokens = parse_user_input(input);
		if (tokens[0] != NULL)
		{
			if (pat_shell_exit_builtin(tokens[0]))
			{
				pat_execute_builtin(tokens[0]);
			} else
			{
				shell_execute_command(tokens[0], tokens);
			}
		}
		free(input);
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
}

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

	while (status)
	{
		input = user_input();
		tokens = parse_user_input(input);
		if (!input)
		{
			break;
		}

		shell_execute_command(tokens[0], tokens);
		free(input);
		free(tokens);
	}
}

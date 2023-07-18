#include "shell_main.h"
/**
 * pat_shell_loop - function that loop shell 
 *
 */
void pat_shell_loop(void)
{
	char **input;
	int status = 1;

	while(status)
	{
		input = user_input();
		if (!input)
		{
			break;
		}
		shell_execute_command(input, &arg[1]);
		free(input);
	}
}


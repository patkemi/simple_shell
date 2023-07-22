#include "shell_main.h"

void pat_execute_builtin(char* command)
{
	extern char **environ;
	int i;

	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	} else if (strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}
}

#include "shell_main.h"
/**
 * main - main function
 * @argc: unused command line argument
 * @argv: argument vector
 * Return: the status of the data
 */

int main(int argc, char **argv)
{
	simple_shell *shell;

	(void)argc;
	shell = (simple_shell *)malloc(sizeof(simple_shell));
	if (shell == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	init_shell(shell);

	shell_loop(argv, shell);


	free(shell);
	return (0);
}

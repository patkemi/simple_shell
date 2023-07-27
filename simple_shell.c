#include "shell_main.h"
/**
 * main - main function
 * @ac: unused command line argument
 * @av: argument vector
 * Return: the status of the data
 */
int main(int ac, char **av)
{
	simple_shell shell;

	(void)ac;

	shell.environ = environ;

	shell_loop(av, &shell);
	cleanup(&shell);

	return (0);
}

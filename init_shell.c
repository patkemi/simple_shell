#include "shell_main.h"
/**
 * init_shell - function that initializes the shell.
 * @shell: a pointer the the struct shell.
 *
 */
void init_shell(simple_shell *shell)
{
	shell->input = NULL;
	shell->args = NULL;
	shell->pid = 0;
}

#include "shell_main.h"

/**
 * pat_shell_exit_builtin: Checks if the given command is
 * the "exit" built-in command.
 * Arguments: command: The command to check.
 *
 * Returns:
 *   - 1 if the command is "exit", indicating it's a built-in command.
 *   - 0 otherwise, meaning it's not the "exit" command.
 */

int pat_shell_exit_builtin(char *command)
{
	return (strcmp(command, "exit") == 0) || (strcmp(command, "env") == 0);
}

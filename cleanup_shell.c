#include "shell_main.h"
/**
 * cleanup - frees allocated memory
 * @shell: pointer to the struct
 *
 */
void cleanup(simple_shell *shell)
{
	free(shell->args);
}

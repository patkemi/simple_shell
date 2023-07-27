#include "shell_main.h"
/**
 * _sigint - function that send SIGINT signal to control CTR C
 * @signal: signal to receive.
 */
void _sigint(int __attribute__ ((unused)) signal)
{
	write(STDOUT_FILENO, "\n^-^ ", 5);
}


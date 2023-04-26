#include "main.h"

/**
 * get_sigint - Handle the CTRL+C call in the shell prompt
 * @sig: The signal number received
 */
void get_sigint(int sig)
{
	(void)sig;  /* Ignore the unused parameter warning */
	write(STDOUT_FILENO, "\n^-^ ", 5);  /* Print a message to the console */
0}


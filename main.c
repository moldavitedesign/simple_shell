#include "main.h"

/**
 * free_data - Frees memory used by the data structure
 *
 * @datash: data structure to be freed
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->envp[i]; i++)
		free(datash->envp[i]);

	free(datash->envp);
	free(datash->pid);
}

/**
 * set_data - Initializes the data structure
 *
 * @datash: data structure to be initialized
 * @av: argument vector
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->envp = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
		datash->envp[i] = _strdup(environ[i]);

	datash->envp[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point of the shell
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	data_shell datash;

	(void) ac;
	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);

	if (datash.status < 0)
		return (255);

	return (datash.status);
}

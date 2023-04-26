#include "main.h"

/**
 * get_error - selects an error message based on the error code and command
 * @datash: the data_shell structure that contains arguments
 * @eval: the error code
 * Return: the error message
 */
int get_error(data_shell *datash, int eval)
{
	char *error = NULL;

	switch (eval)
	{
		case -1:
			error = error_env(datash);
			break;
		case 126:
			error = error_path_126(datash);
			break;
		case 127:
			error = error_not_found(datash);
			break;
		case 2:
			if (_strcmp("exit", datash->args[0]) == 0)
				error = error_exit_shell(datash);
			else if (_strcmp("cd", datash->args[0]) == 0)
				error = error_get_cd(datash);
			break;
	}

	if (error != NULL)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return eval;
}

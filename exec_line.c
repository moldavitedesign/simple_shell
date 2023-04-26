#include "main.h"

/**
 * execute_line - searches for builtins and commands
 *
 * @datash: data relevant to command execution (args)
 * Return: 1 on success
 */
int execute_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (execute_command(datash));
}

/**
 * get_builtin - finds a built-in command by name
 * @cmd: name of the command
 * Return: pointer to the function that implements the command
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	/* Define the list of built-in commands */
	builtin_t builtins[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	/* Look up the command in the list of built-ins */
	int i;

	for (i = 0; builtins[i].name; i++)

	{
		if (_strcmp(builtins[i].name, cmd) == 0)
			break;
	}

	/* Return a pointer to the function that implements the command */
	return (builtins[i].f)

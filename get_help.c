/**
 * get_help - prints help message for a given command
 * @datash: a pointer to the data shell structure
 * Return: 0 on success, -1 on error
 */
int get_help(data_shell *datash)
{
	const char *help_message;
	const char *command = datash->args[1];

	if (command == NULL)
	{
		aux_help_general();
		return (0);
	}

	if (strcmp(command, "cd") == 0)
	{
		help_message = "Change the current working directory.\n"
			       "Usage: cd [DIRECTORY]\n";
	}
	else if (strcmp(command, "alias") == 0)
	{
		help_message = "Create or display aliases.\n"
			       "Usage: alias [NAME[='VALUE'] ...]\n";
	}
	else if (strcmp(command, "env") == 0)
	{
		help_message = "Print the environment variables.\n";
	}
	else if (strcmp(command, "exit") == 0)
	{
		help_message = "Exit the shell.\n";
	}
	else if (strcmp(command, "help") == 0)
	{
		help_message = "Display information about builtin commands.\n";
	}
	else if (strcmp(command, "setenv") == 0)
	{
		help_message = "Set an environment variable.\n"
			       "Usage: setenv NAME [VALUE]\n";
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		help_message = "Unset an environment variable.\n"
			       "Usage: unsetenv NAME\n";
	}
	else
	{
		dprintf(STDERR_FILENO, "help: no help topics match `%s'. "
			"Try `help help' or `man -k %s' or `info %s'.\n",
			command, command, command);
		return (-1);
	}

	printf("%s", help_message);
	datash->status = 0;
	return (0);
}


#include "main.h"

/**
 * aux_help - Display help information for the built-in help command.
 * Return: void
 */
void aux_help(void)
{
	char *help_msg = "help: help [-dms] [pattern ...]\n"
	"\tDisplay information about built-in commands.\n"
	"\tDisplays brief summaries of built-in commands.\n";

	write(STDOUT_FILENO, help_msg, _strlen(help_msg));
}

/**
 * aux_help_alias - Display help information for the built-in alias command.
 * Return: void
 */
void aux_help_alias(void)
{
	char *help_msg = "alias: alias [-p] [name[=value]...]\n"
	"\tDefine or display aliases.\n";

	write(STDOUT_FILENO, help_msg, _strlen(help_msg));
}

/**
 * aux_help_cd - Display help information for the built-in cd command.
 * Return: void
 */
void aux_help_cd(void)
{
	char *help_msg = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n"
	"\tChange the shell working directory.\n";

	write(STDOUT_FILENO, help_msg, _strlen(help_msg));
}


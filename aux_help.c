#include "main.h"

/**
 * aux_help_env - Help information for the builtin env command
 * Return: no return
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));


	help = "Prints the environment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_setenv - Help information for the builtin setenv command
 * Return: no return
 */
void aux_help_setenv(void)
{
	char *help = "setenv: setenv (const char *name,

	const char *value, int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));

	help = "Adds a new definition to the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_unsetenv - Help information for the builtin unsetenv command
 * Return: no return
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));

	help = "Removes an entry completely from the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_general - Entry point for help
 * information for the help builtin command
 * Return: no return
 */
void aux_help_general(void)

{

	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));

help = "These commands are defined internally. Type 'help' to see the list.\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n";
	write(STDOUT_FILENO, help, _strlen(help));

	help = "alias: alias [name=['string']]\n"
	       "cd: cd [-L|[-P [-e]] [-@]] [dir]\n"
	       "exit: exit [n]\n"
	       "env: env [option] [name=value] [command [args]]\n"
	       "setenv: setenv [variable] [value]\n"
	       "unsetenv: unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_exit - Help information for the builtin exit command
 * Return: no return
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n"
	"Exit shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));

	help = "Exits the shell with a status of N.If N is ommited,
	the exit status is that of the last command executed.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}


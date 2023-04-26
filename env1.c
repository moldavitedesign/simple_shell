#include "main.h"

/**
 * cmp_env_name - compare environment variable names
 * @nenv: the name of the environment variable
 * @name: the name to compare with
 *
 * Return: 0 if the names are not equal, otherwise returns a non-zero value
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i = 0;

	while (nenv[i] != '=')
	{
	if (nenv[i] != name[i])
	{
	return (0);
	}
	i++;
	}

	return (i + 1);
}

/**
 * _getenv - get the value of an environment variable
 * @name: the name of the environment variable
 * @_environ: the environment variable
 *
 * Return: the value of the environment
 * variable if found, otherwise returns NULL
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env = NULL;
	int i, mov;
mov = 0;

	for (i = 0; _environ[i] != NULL; i++)
	{
	mov = cmp_env_name(_environ[i], name);

	if (mov)
	{
	ptr_env = _environ[i];
	break;
	}
	}

	return (ptr_env + mov);
	}

/**
 * _env - print the environment variables
 * @datash: relevant data
 *
 * Return: 1 on success
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i] != NULL; i++)
	{
	for (j = 0; datash->_environ[i][j] != '\0'; j++)
	;

	write(STDOUT_FILENO, datash->_environ[i], j);
	write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}


#include "main.h"

/**
 * error_env - returns an error message related to environment variables
 * @datash: data relevant to the shell
 *
 * Return: The error message string.
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg = ": Unable to add/remove from environment\n";

	ver_str = aux_itoa(datash->counter);
	if (ver_str == NULL)
		return (NULL);

	length = _strlen(datash->av[0])
	+ _strlen(ver_str) + _strlen(datash->args[0]) +
		_strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - returns an error message
 * related to path and permission denied
 * @datash: data relevant to the shell
 *
 * Return: The error message string.
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	if (ver_str == NULL)
		return (NULL);

	length = _strlen(datash->av[0]) + _strlen(ver_str)
	+ _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	free(ver_str);

	return (error);
}


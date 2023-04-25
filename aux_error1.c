#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag = NULL;
	size_t length = 0;

	/* Concatenate the error message */
	length = snprintf(error, MAX_ERROR_LENGTH, "%s: %s: %s%s",
	datash->av[0], ver_str, datash->args[0], msg);
	/*  If the second argument starts with "-", */
	/*  then add the illegal flag to the error message */
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		length += snprintf(error + length, MAX_ERROR_LENGTH - length,
		"%s", illegal_flag);
		free(illegal_flag);
	}
	else
	{
		length += snprintf(error + length,
		MAX_ERROR_LENGTH - length, "%s", datash->args[1]);
	}

	length += snprintf(error + length, MAX_ERROR_LENGTH - length, "\n");

	/* Ensure that the error message is properly terminated */
	error[length] = '\0';
return ();
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *datash)
{
	size_t length = 0, len_id = 0;
	char *error = NULL, *ver_str = NULL, *msg = NULL;

	/*  Get the version string of the current shell command */
	ver_str = aux_itoa(datash->counter);

	/* Determine the type of error message to generate */
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = strlen(datash->args[1]);
	}

	/* Calculate the length of the error message */
	length = snprintf(NULL, 0, "%s: %s: %s%s%s\n",
	datash->av[0], ver_str, datash->args[0], msg, datash->args[1]);

	/* Allocate memory for the error message */
	error = malloc(length + 1);

	if (error != NULL)
	{
		/* Generate the error message */
		snprintf(error, length + 1, "%s: %s: %s%s%s\n",
		datash->av[0], ver_str, datash->args[0], msg, datash->args[1]);
	}

	/*  Free the version string */
	free(ver_str);
return ();

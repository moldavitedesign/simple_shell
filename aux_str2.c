#include "main.h"

/**
 * string_dup - duplicates a string in the heap memory.
 * @s: pointer to string to duplicate.
 *
 * Return: pointer to newly allocated string, or NULL if malloc fails.
 */
char *string_dup(const char *s)
{
char *new_str;
	size_t len;

	len = strlen(s);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	memcpy(new_str, s, len + 1);
	return (new_str);
}

/**
 * string_length - Returns the length of a string.
 * @s: pointer to string.
 *
 * Return: length of string.
 */
int string_length(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
	{
	}
	return (len);
}

/**
 * compare_chars - compare characters of strings
 * @str: input string.
 * @delim: delimiter string.
 *
 * Return: 1 if the characters are equal, 0 otherwise.
 */
int compare_chars(char *str, const char *delim)
{
	unsigned int i, j, k;

for (i = 0, k = 0; str[i] != '\0'; i++)
	{

for (j = 0; delim[j] != '\0'; j++)
		{
if (str[i] == delim[j])
			{
k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * string_tokenizer - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter string.
 *
 * Return: string split by delimiter.
 */
char *string_tokenizer(char *str, const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (compare_chars(str, delim))
			return (NULL);
		splitted = str; /* Store first address */
		i = string_length(str);
		str_end = &str[i]; /* Store last address */
	}
	str_start = splitted;
	if (str_start == str_end) /* Reached the end */
		return (NULL);

	for (bool = 0; *splitted != '\0'; splitted++)
	{
		/* Break loop finding the next token */
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/* Replace delimiter for null char */
		for (i = 0; delim[i] != '\0'; i++)
{
			if  (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted != '\0') /* str is not delim */
			bool = 1;
	}
	if (bool == 0) /* str is delim */
		return (NULL);
	return (str_start);
}

/**
 * is_digit - defines if string passed is a number.
 *
 * @s: input string.
 * Return: 1 if string is a number, 0 otherwise.
 */
int is_digit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1)


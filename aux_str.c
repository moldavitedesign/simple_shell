#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string pointer.
 * @src: Source string pointer.
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
	size_t i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: Destination string pointer.
 * @src: Source string pointer.
 * Return: Pointer to the resulting string.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: String pointer to be compared.
 * @s2: String pointer to be compared.
 * Return: Returns an integer greater than, equal to, or less than 0,
 * according as the string s1 is greater than, equal to, or less than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	size_t i;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (0);
}

/**
 * _strchr - Returns a pointer to the first
 * occurrence of a character in a string.
 * @s: String pointer to be searched.
 * @c: Character to be searched.
 * Return: Returns a pointer to the first
 * occurrence of the character c in the string s,
 * or NULL if the character is not found.
 */
char *_strchr(const char *s, int c)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
	}
if (c == '\0')
return ((char *)&s[i]);

	return (NULL);
}

/**
 * _strspn - Calculates the length of the initial segment of a string
 * which consists entirely of characters from another string.
 * @s: String to be checked.
 * @accept: String containing the characters to match.
 * Return: Returns the number of characters
 * found in s which are also in accept.
 */
size_t _strspn(const char *s, const char *accept)
{
	size_t i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				break;
		}

		if (accept[j] == '\0')
			return (i);
	}

	return (i);
}


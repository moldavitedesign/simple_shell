#include "main.h"

/**
 * rev_string - Reverses a given string.
 * @s: Pointer to the string to be reversed.
 */
void rev_string(char *s)
{
	int len = 0, i, j;
	char temp;

    /* Compute the length of the string */
	while (s[len] != '\0')
	len++;

    /* Reverse the string using a two-pointer approach */
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	}
}


#include <stdlib.h>
/**
 * get_num_length - Returns the number of digits in an integer.
 * @n: The integer to check.
 *
 * Return: The number of digits in n.
 */
int get_num_length(int n)
{
	unsigned int num;
	int length = 1;

	if (n < 0)
	{
		length++;
		num = n * -1;
	}
	else
	{
		num = n;
	}

	while (num > 9)
	{
		length++;
		num /= 10;
	}

	return (length);
}

/**
 * int_to_string - Converts an integer to a string.
 * @n: The integer to convert.
 *
 * Return: The string representation of n.
 */
char *int_to_string(int n)
{
	unsigned int num;
	int length = get_num_length(n);
	char *str;

	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);

	str[length] = '\0';
	if (n < 0)
	{
		num = n * -1;
		str[0] = '-';
	}
	else
	{
		num = n;
	}

	length--;
	do {
		str[length] = (num % 10) + '0';
		num /= 10;
		length--;
	} while (num > 0);

	return (str);
}

/**
 * string_to_int - Converts a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer representation of str.
 */
int string_to_int(char *str)
{
	unsigned int count = 0, size = 0, num = 0,
	sign = 1, mult = 1, i;

	while (*(str + count) != '\0')
		{
		if (size > 0 && (*(str + count) < '0'
		|| *(str + count) > '9'))
			break;

		if (*(str + count) == '-')
			sign *= -1;

		if (*(str + count) >= '0' &&
		*(str + count) <= '9') {
			if (size > 0)
				mult *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		num += (*(str + i) - '0') * mult;
		mult /= 10;
	}

	return (num * sign);
}


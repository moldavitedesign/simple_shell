#include "main.h"

/**
 * read_line - Read a line from stdin.
 *
 * @i_eof: Pointer to integer that will hold the getline() return value.
 *
 * Return: The input string.
 */
char *read_line(int *i_eof)
{
    char *input = NULL;
    size_t bufsize = 0;

    *i_eof = getline(&input, &bufsize, stdin);
    if (*i_eof == -1)
    {
        free(input);
        input = NULL;
    }

    return (input);
}

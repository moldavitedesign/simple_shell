#include "main.h"

/**
 * Removes comments from the given input string.
 *
 * @param in The input string.
 * @return The input string without comments, or NULL if the input string is invalid.
 */
char *remove_comments(char *in)
{
    int i, up_to;

    up_to = 0;
    for (i = 0; in[i]; i++)
    {
        if (in[i] == '#')
        {
            if (i == 0)
            {
                free(in);
                return NULL;
            }

            if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
            {
		    up_to = i;
            }
        }
    }

    if (up_to != 0)
    {
        in = _realloc(in, i, up_to + 1);
        in[up_to] = '\0';
    }

    return in;
}

/**
 * Main loop of the shell.
 *
 * @param datash A pointer to the data relevant to the shell.
 */
void shell_loop(data_shell *datash)
{
    int loop, i_eof;
    char *input;

    loop = 1;
    while (loop == 1)
    {
        write(STDIN_FILENO, "^-^ ", 4);
        input = read_line(&i_eof);
        if (i_eof != -1)
        {
            input = remove_comments(input);
            if (input == NULL)
            {
                continue;
            }

            if (check_syntax_error(datash, input) == 1)
            {
                datash->status = 2;
                free(input);
                continue;
            }
	    input = replace_variables(input, datash);
            loop = split_commands(datash, input);
            datash->counter += 1;
            free(input);
        }
        else
        {
            loop = 0;
            free(input);
        }
    }
}

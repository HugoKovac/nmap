#include "parsing.h"
#include <stdio.h>

/*
    if ptr->arg == true and !av[i + 1] return error
    if ptr->arg == true ptr->data = av[i + 1] and av[i + 1] = NULL

    av[i] = NULL
*/
bool arg_check(s_input *ptr, int idx, char **av)
{
    if (ptr->argument)
    {
        if (!av[idx + 1])
        {
            dprintf(2, "option requires an argument %s '%s'\n", (ptr->type == DOUBLE ? "--" : "-"), ptr->symbol);
            return false;
        }
        ptr->data = av[idx + 1];
        av[idx + 1] = NULL; // remove the arg from av to not loop to it again
    }
    else
    {
        ptr->data = (void*)1;
    }
    av[idx] = NULL; // remove from av to not loop to it again

    return true;
}

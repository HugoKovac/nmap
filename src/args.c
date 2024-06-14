#include "parsing.h"
#include <stdio.h>

bool arg_help(char *help_msg, s_input *help_node)
{
    if (help_node->data == (void*)1){
        puts(help_msg);
        return true;
    }
    return false;
}

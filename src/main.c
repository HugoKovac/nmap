#include <stdio.h>
#include <ctype.h>
#include "parsing.h"

int main(int ac, char **av)
{
    char *out = NULL;

    s_input o_help = {
        SIMPLE, // Type
        "h",    // symbol
        out,    // data
        true,   // argument
        true,   // unique
        false,  // no_flag
        NULL};

    s_input o_verbose = {
        SIMPLE,
        "v",
        out,
        false,
        false,
        false,
        &o_help};

    s_input o_fin = {
        NMAP,
        "sF",
        out,
        false,
        false,
        false,
        &o_verbose};

    s_input o_oui = {
        DOUBLE,
        "oui",
        out,
        true,
        false,
        false,
        &o_fin};

    if (!parsing(ac, av, "default", &o_oui))
    {
        // dprintf(2, "ERROR\n");
        return 255;
    }

    return 0;
}
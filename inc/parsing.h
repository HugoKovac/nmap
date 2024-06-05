#ifndef PARSING_H
#define PARSING_H

#include <stdbool.h>

typedef enum Type e_type;
typedef struct Input s_input;

enum Type
{
    SIMPLE, // -
    DOUBLE, // --
    NMAP    // -aA || -A0
};

struct Input
{
    e_type type;
    char *symbol;   // SIMPLE: str len 1 | DOUBLE: str len >= 1 
    char *data;     // char* with string following the flag, NULL if argument == false
    bool argument;  // Is the flag followed by an argument to be pointed by data
    bool unique;    // Is it possible to have mutliple time the same flag
    bool no_flag;   // true when node has been created after the flag parsing (valid arg but without (known) flag) 
    s_input *next;
};


s_input *parsing(int ac, char **av, char *default_output, s_input *options);
bool arg_check(s_input *ptr, int idx, char **av);

#endif

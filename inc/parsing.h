#ifndef PARSING_H
#define PARSING_H

#include <stdbool.h>

typedef enum Type e_type;
typedef struct Input s_input;

enum Type
{
    SIMPLE, // -
    DOUBLE, // --
    NMAP,    // -aA || -A0
    NO_FLAG // true when node has been created after the flag parsing (valid arg but without (known) flag)
};

struct Input
{
    e_type type;
    char *symbol;   // SIMPLE: str len 1 | DOUBLE: str len >= 1 
    char *data;     // char* with string following the flag, NULL if argument == false
    bool argument;  // Is the flag followed by an argument to be pointed by data
    s_input *next;
};


s_input *parsing(int ac, char **av, char *default_output, s_input *options);
bool arg_check(s_input *ptr, int idx, char **av);
bool add_back(s_input **head, e_type type, char *symbol, bool argument);
void freeList(s_input *head);
bool parsed(s_input **head);
void print_linked_list(s_input *head);
bool arg_help(char *help_msg, s_input *help_node);
bool ping(char *host);


#endif

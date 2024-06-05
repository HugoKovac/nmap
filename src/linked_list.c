#include "parsing.h"
#include <ctype.h>
#include <stdlib.h>

void freeList(s_input *head)
{
    if (head)
    {
        freeList(head->next);
        free(head);
    }
}

void add_back(s_input **head, e_type type, char *symbol, bool argument)
{

    s_input *new = NULL;
    new = malloc(sizeof(s_input));
    if (!new)
        return;
    *new = (s_input){0};

    new->type = type;
    new->symbol = symbol;
    new->data = NULL;
    new->argument = argument;
    new->next = NULL;

    if (!*head)
    {
        *head = new;
    }
    else
    {
        s_input *cpy = *head;

        while (cpy->next)
        {
            cpy = cpy->next;
        }
        cpy->next = new;
    }
}
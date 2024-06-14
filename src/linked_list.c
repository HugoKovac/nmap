#include "parsing.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_linked_list(s_input *head)
{
    s_input *cpy = head;

    while (cpy->next)
    {
        printf("ptr [%p]\n", cpy);

        printf("type: ");
        switch (cpy->type)
        {
        case SIMPLE:
            puts("SIMPLE");
            break;
        case DOUBLE:
            puts("DOUBLE");
            break;
        case NMAP:
            puts("NMAP");
            break;
        default:
            puts("NO_FLAG");
            break;
        }

        printf("symbol(%p): %s\n", cpy->symbol, cpy->symbol);
        printf("data(%p): %s\n", cpy->data, cpy->data);
        printf("argument: %s\n", cpy->argument ? "True" : "False");
        printf("next: %p\n", cpy->next);
        printf("\n%0*d\n\n", 110, 0);

        cpy = cpy->next;
    }
}

void freeList(s_input *head)
{
    if (head)
    {
        freeList(head->next);
        free(head->symbol);
        head->symbol = NULL;
        free((s_input *)head);
        head = NULL;
    }
}

bool add_back(s_input **head, e_type type, char *symbol, bool argument)
{

    s_input *new = NULL;
    new = (s_input *)malloc(sizeof(s_input));
    if (!new)
        return true;
    *new = (s_input){0};

    new->type = type;
    new->symbol = strdup(symbol);
    if (!new->symbol){
        free(new);
        return true;
    }
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

    return false;
}
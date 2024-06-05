#include <stdio.h>
#include <ctype.h>
#include "parsing.h"

int main(int ac, char **av)
{
    s_input *head = NULL;

    add_back(&head, DOUBLE, "help", true);
    add_back(&head, DOUBLE, "ports", true);
    add_back(&head, DOUBLE, "ip", true);
    add_back(&head, DOUBLE, "speedup", true);
    add_back(&head, DOUBLE, "scan", true);
    add_back(&head, DOUBLE, "file", true);

    if (!head){
        dprintf(2, "Allocation error\n");
        return 1;
    }

    s_input *cpy = head;

    while (cpy->next)
    {
        // printf("%p\n", cpy);
        // printf("%s\n", cpy->symbol);
        cpy = cpy->next;
    }

    freeList(head);

    if (!parsing(ac, av, "default", head))
    {
        // dprintf(2, "ERROR\n");
        return 255;
    }

    return 0;
}
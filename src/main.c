#include <stdio.h>
#include "parsing.h"

int main(int ac, char **av)
{
    s_input *head = NULL;
    bool alloc_error = false;

    alloc_error |= add_back(&head, DOUBLE, "help", false);
    alloc_error |= add_back(&head, DOUBLE, "ports", true);
    alloc_error |= add_back(&head, DOUBLE, "ip", true);
    alloc_error |= add_back(&head, DOUBLE, "speedup", true);
    alloc_error |= add_back(&head, DOUBLE, "scan", true);
    alloc_error |= add_back(&head, DOUBLE, "file", true);

    if (!head || alloc_error)
    {
        dprintf(2, "Allocation error\n");
        return 1;
    }

    // print_linked_list(head);
    char *help_msg = "Help Screen\n\
        ft_nmap [OPTIONS]\n\
        --help Print this help screen\n\
        --ports ports to scan (eg: 1-10 or 1,2,3 or 1,5-15)\n\
        --ip ip addresses to scan in dot format\n\
        --file File name containing IP addresses to scan,\n\
        --speedup [250 max] number of parallel threads to use\n\
        --scan SYN/NULL/FIN/XMAS/ACK/UDP";

    if (!parsing(ac, av, help_msg, head))
    {
        // dprintf(2, "ERROR\n");
        freeList(head);
        return 255;
    }
    if (arg_help(help_msg, head))
    {
        freeList(head);
        return 0;
    }
    if (!parsed(&head))
    {
        freeList(head);
        return 2;
    }

    
    if (ping(head->next->next->data))
    {
        freeList(head);
        return 3;
    }

    // print_linked_list(head);

    freeList(head);

    return 0;
}
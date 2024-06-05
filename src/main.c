#include <stdio.h>
#include <ctype.h>
#include "parsing.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    /*
        Create utils for linked list:
        Add back,
        Free All
    */
    // s_input o_help = {
    //     DOUBLE, // Type
    //     "help",    // symbol
    //     out,    // data
    //     true,   // argument
    //     true,   // unique
    //     NULL};

    // s_input o_ports = {
    //     DOUBLE,
    //     "ports",
    //     out,
    //     true,
    //     true,
    //     &o_help};

    // s_input o_ip = {
    //     DOUBLE,
    //     "ip",
    //     out,
    //     true,
    //     true,
    //     &o_ports};

    // s_input o_speedup = {
    //     DOUBLE,
    //     "speedup",
    //     out,
    //     true,
    //     true,
    //     &o_ip};

    // s_input o_scan = {
    //     DOUBLE,
    //     "scan",
    //     out,
    //     true,
    //     true,
    //     &o_speedup};

    // s_input o_file = {
    //     DOUBLE,
    //     "file",
    //     out,
    //     true,
    //     true,
    //     &o_scan};

    s_input *head = NULL;

    // printf("%p\n", *head);

    add_back(&head, DOUBLE, "help", true, true);
    add_back(&head, DOUBLE, "ports", true, true);
    add_back(&head, DOUBLE, "ip", true, true);
    add_back(&head, DOUBLE, "speedup", true, true);
    add_back(&head, DOUBLE, "scan", true, true);
    add_back(&head, DOUBLE, "file", true, true);

    if (!head){
        dprintf(2, "Allocation error\n");
        return 1;
    }

    s_input *cpy = head;

    while (cpy->next)
    {
        printf("%p\n", cpy);
        printf("%s\n", cpy->symbol);
        cpy = cpy->next;
    }

    freeList(head);

    // if (!parsing(ac, av, "default", &o_file))
    // {
    //     // dprintf(2, "ERROR\n");
    //     return 255;
    // }

    return 0;
}
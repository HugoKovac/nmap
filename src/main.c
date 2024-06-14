#include <stdio.h>
#include <ctype.h>
#include "parsing.h"

int main(int ac, char **av)
{
	s_input *head = NULL;
    bool alloc_error = false;

	alloc_error |= add_back(&head, DOUBLE, "help", true);
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

	if (!parsing(ac, av, "default", head))
	{
		dprintf(2, "ERROR\n");
		return 255;
	}
	if (!parsed(&head))
	{
		freeList(head);
		return 2;
	}

    print_linked_list(head);

	freeList(head);

	return 0;
}
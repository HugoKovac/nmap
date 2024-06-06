#include "parsing.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

bool parsed(s_input **head)
{
	s_input *ptr = *head;
	s_input *address = NULL;
	while (ptr)
	{
		if (!strcmp(ptr->symbol, "file") || !strcmp(ptr->symbol, "ip"))
		{
			if (ptr->data)
			{
				if (address)
				{
					dprintf(2, "%p\n", address);
					dprintf(2, "You can't give --ip and --file at the same time\n");
					return false;
				}
				else
					address = ptr;
			}
		}
		if (ptr->type == NO_FLAG){
			dprintf(2, "'%s' is not a known argument\n", ptr->data);
			return false;
		}
		ptr = ptr->next;
	}

	if (!address)
	{
		dprintf(2, "You should provide --ip or --file argument\n");
		return false;
	}

	return true;
}
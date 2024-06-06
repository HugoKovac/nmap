#include "parsing.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void freeList(s_input *head)
{
	if (head)
	{
		freeList(head->next);
		free(head->symbol);
		free((s_input *)head);
	}
}

void add_back(s_input **head, e_type type, char *symbol, bool argument)
{

	s_input *new = NULL;
	new = (s_input *)malloc(sizeof(s_input));
	if (!new)
		return;
	*new = (s_input){0};

	new->type = type;
	new->symbol = strdup(symbol);
	new->data = NULL;
	new->argument = argument;
	new->next = NULL;
	if (!new->symbol)
	{
		free(new);
		return;
	}

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
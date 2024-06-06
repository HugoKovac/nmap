#include "parsing.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

s_input *parsing(int ac, char **av, char *default_output, s_input *options)
{
	if (ac == 1)
	{
		puts(default_output);
		return NULL;
	}

	s_input *ptr = options;
	int len = 0;
	for (; av[len]; len++)
	{
	}
	while (ptr)
	{
		for (int i = 1; i < len; i++)
		{
			if (!av[i])
			{
				continue;
			}
			else if (strstr(av[i], "--") && !strcmp(av[i] + 2, ptr->symbol)) // --arg
			{
				// puts("DOUBLE");
				if (!arg_check(ptr, i, av))
					return NULL;
			}
			else if (strstr(av[i], "-") &&
					 strlen(av[i]) == 2 &&
					 !strcmp(av[i] + 1, ptr->symbol)) // -a
			{
				// puts("SIMPLE");
				if (!arg_check(ptr, i, av))
					return NULL;
			}
		}
		ptr = ptr->next;
	}
	for (int i = 1; i < len; i++)
	{
		ptr = options;
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		if (av[i])
		{
			// printf("remains: %s\n", av[i]);
			// Create a new node ?
			ptr->next = malloc(sizeof(s_input));
			if (ptr->next)
			{
				*(ptr->next) = (s_input){0};
				ptr->next->type = NO_FLAG;
				ptr->next->symbol = NULL;
				ptr->next->data = av[i];
				ptr->next->argument = false;
				ptr->next->next = NULL;
			}
		}
		ptr = ptr->next;
	}
	// DEBUG VIEW LINK LIST
	ptr = options;
	while (ptr)
	{
		if (ptr->data)
		{
			printf("%s: %s\n", ptr->symbol, ptr->data);
		}
		else
		{
			printf("%s: no data\n", ptr->symbol);
		}
		ptr = ptr->next;
	}

	return options;
}
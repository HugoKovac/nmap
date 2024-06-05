#include "parsing.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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
            else if (strstr(av[i], "-") &&
                     strlen(av[i]) == 3 &&
                     ((islower(av[i][1]) && isupper(av[i][2])) ||  // -sA
                      (isupper(av[i][1]) && isdigit(av[i][2]))) && // T5
                     !strcmp(av[i] + 1, ptr->symbol))
            {
                // puts("NMAP");
                if (!arg_check(ptr, i, av))
                    return NULL;
            }
        }
        ptr = ptr->next;
    }
    for (int i = 1; i < len; i++)
    {
        if (av[i])
        {
            // printf("remains: %s\n", av[i]);
            // print("2nd check ptr = %p\n", )
            s_input *cpy = options;
            while (cpy->next)
            {
                cpy = cpy->next;
                printf("%p\n", cpy->next);
            }
            // Create a new node ?
            cpy->next = &(s_input){
                NO_FLAG,
                NULL,
                av[i],
                true,
                false,
                NULL};
            // printf(">> %s -> %p (%s)\n", cpy->symbol, cpy->next, av[i]);
            cpy = options;
            // while (cpy)
            // {
            //     printf("%s -> %s\n", cpy->symbol, cpy->data);
            //     cpy = cpy->next;
            // }
        }
    }

    return options;
}
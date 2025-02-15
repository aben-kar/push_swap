#include "push_swap.h"

char **parse_arguments(int ac, char **av)
{
    char **args;
    int i = 1;
    int j = 0;
    int arg_count = 0;

    int k = 1;
    while (k < ac)
    {
        arg_count += count_word(av[k], ' ');
        k++;
    }

    args = malloc((arg_count + 1) * sizeof(char *));
    if (!args)
        return NULL;

    i = 1;
    while (i < ac)
    {
        if (!(*av[i]))
        {
            write (2, "Error\n", 6);
            exit(1);
        }
        else if (*av[i] && ft_strchr(av[i], ' '))
        {
            char **split_args = ft_split(av[i], ' ');
            if (!split_args)
                return NULL;

            int k = 0;
            while (split_args[k])
            {
                args[j] = split_args[k];
                k++;
                j++;
            }
        }
        else
        {
            args[j] = av[i];
            j++;
        }
        i++;
    }
    args[j] = NULL;

    return (args);
}
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
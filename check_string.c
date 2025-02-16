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
        arg_count += count_word(av[k], " \t");
        k++;
    }

    args = malloc((arg_count + 1) * sizeof(char *));
    if (!args)
        return NULL;

    for (int x = 0; x < arg_count + 1; x++) // Initialisation correcte
        args[x] = NULL;

    i = 1;
    while (i < ac)
    {
        if (!av[i] || is_only_spaces(av[i]))
        {
            write(2, "Error\n", 6);
            ft_free(args);
            return (NULL);
        }

        if (ft_strchr(av[i], ' ') || ft_strchr(av[i], '\t'))
        {
            char **split_args = ft_split(av[i], " \t");
            if (!split_args)
            {
                ft_free(args);
                return (NULL);
            }

            int k = 0;
            while (split_args[k])
            {
                args[j] = ft_strdup(split_args[k]);
                if (!args[j])
                {
                    ft_free(split_args);
                    ft_free(args);
                    return (NULL);
                }
                k++;
                j++;
            }
            ft_free(split_args);
        }

        else
        {
            args[j] = ft_strdup(av[i]);
            if (!args[j])
            {
                ft_free(args);
                return (NULL);
            }
            j++;
        }
        i++;
    }
    args[j] = NULL;

    return (args);
}
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
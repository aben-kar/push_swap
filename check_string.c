#include "push_swap.h"

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node *parse_arguments(int ac, char **av)
{
    int i;
    Node *head = NULL;
    i = 1;
    while (i < ac)
    {
        if (!av[i] || is_only_spaces(av[i]))
        {
            write(2, "espace-->Error\n", 15);
            free_list(&head);
            return (NULL);
        }

        if (ft_strchr(av[i], ' ') || ft_strchr(av[i], '\t'))
        {
            char **split_args = ft_split(av[i], " \t");
            if (!split_args)
            {
                free_list(&head);
                return (NULL);
            }

            int k = 0;
            while (split_args[k])
            {
                if (cree_node(&head, ft_atoi(split_args[k])) != 0)
                {
                    ft_free(split_args);
                    free_list(&head);
                    return (NULL);
                }
                k++;
            }
            ft_free(split_args);
        }

        else
        {
            if (cree_node(&head, ft_atoi(av[i])) != 0)
            {
                free_list(&head);
                return (NULL);
            }
        }
        i++;
    }

    return head;
}

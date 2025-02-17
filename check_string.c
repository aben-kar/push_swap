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
    int num;
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

        // if (!is_valid_sign(av[i]))
        // {
        //     write(2, "sign-->Error\n", 13);
        //     free_list(&head);
        //     return (NULL);
        // }

        if (ft_strchr(av[i], ' '))
        {
            char **split_args = ft_split(av[i], ' ');
            if (!split_args)
            {
                free_list(&head);
                return (NULL);
            }

            int k = 0;
            while (split_args[k])
            {
                num = ft_atoi(split_args[k]);
                if (num == -1)
                {
                    ft_free(split_args);
                    free_list(&head);
                    return (NULL);
                }
                if (repetition(&head, num))
                {
                    write(2, "repetetion-->Error\n", 19);
                    free_list(&head);
                    return (NULL);                
                }
                if (cree_node(&head, num) != 0)
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
            num = ft_atoi(av[i]);
            if (num == -1)
            {
                free_list(&head);
                return (NULL);
            }
            if (repetition(&head, num))
            {
                write(2, "repetetion-->Error\n", 19);
                free_list(&head);
                return (NULL);
            }
            if (cree_node(&head, num) != 0)
            {
                free_list(&head);
                return (NULL);
            }
        }
        i++;
    }

    return head;
}

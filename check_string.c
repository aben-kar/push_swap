#include "push_swap.h"

int handle_spaced_argument(char *arg, Node **head)
{
    char **split_args = ft_split(arg, ' ');
    if (!split_args)
    {
        free_list(head);
        return (1); // (Error)
    }
    int k = -1;
    while (split_args[++k])
    {
        int num = ft_atoi(split_args[k]);
        if (num == -1)
        {
            free_list(head);
            ft_free(split_args);
            return (1); // (Error)
        }
        if (repetition(head, num) || cree_node(head, num) != 0)
        {
            ft_free(split_args);
            free_list(head);
            return (write_error("Error")); // (Error)
        }
    }
    ft_free(split_args);
    return (0); // (Success)
}
int handle_single_argument(char *arg, Node **head)
{
    int num = ft_atoi(arg);
    if (num == -1)
        {
            free_list(head);
            return (1); // (Error)
        }
    if (repetition(head, num) || cree_node(head, num) != 0)
    {
        free_list(head);
        return (write_error("Error")); // (Error)
    }
    return (0); // (Success)
}
int validate_argument(char *arg)
{
    if (!arg || is_only_spaces(arg))
    {
        write(2, "Error\n", 6);
        return (1); // (Error)
    }
    return (0); // (Success)
}
Node *parse_arguments(int ac, char **av)
{
    int i = 1;
    Node *head = NULL;

    while (i < ac)
    {
        if (validate_argument(av[i]))
        {
            free_list(&head);
            return (NULL);
        }

        if (ft_strchr(av[i], ' '))
        {
            if (handle_spaced_argument(av[i], &head) != 0)
                return (NULL);
        }
        else
        {
            if (handle_single_argument(av[i], &head) != 0)
                return (NULL);
        }
        i++;
    }

    return head;
}

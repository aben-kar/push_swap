#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        Node *a = NULL;
    //  Node *b = NULL;

        if ((ac == 2 && !av[1][0]))
            return 1;
        // if (ac == 2)
        //     av = ft_split(av[1], ' ');
        stack_a(&a, av + 1);
        Node *current = a;
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}
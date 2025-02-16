#include "push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if ((char)c == *str)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        Node *a = NULL;
        // Node *b = NULL;

        if ((!av[1][0]))
        {
            write (2, "empty-->Error\n", 14);
            return 1;
        }
        
        Node *number = parse_arguments(ac, av);
        if (!number)
        {
            free_list(&number);
            return (1);
        }

        if (stack_a(&a, number) != 0)
        {
            free_list(&number);
            return 1;
        }

        printList(a);
        // printList(b);
        free_list(&a);

        free_list(&number);
    }
}
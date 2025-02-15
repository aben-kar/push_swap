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
            write (2, "Error\n", 6);
            return 1;
        }
        char **number = parse_arguments(ac, av);

        stack_a(&a, number);

        printList(a);
        // printList(b);
    }
}

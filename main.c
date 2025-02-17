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
        Node *a;
        // Node *b = NULL;
        
        a = parse_arguments(ac, av);
        if (!a)
        {
            free_list(&a);
            return (1);
        }
        
        // pb(&a, &b);
        // pb(&a, &b);
        // sa(&a);
        // sb(&b);
        // pa(&a, &b);
        // pa(&a, &b);

        printList(a);
        // printList(b);

        free_list(&a);
        // free_list(&b);
    }
}
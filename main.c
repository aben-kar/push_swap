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

// int main(int ac, char **av)
// {
//     if (ac > 1)
//     {
//         Node *a = NULL;

//         if ((ac == 2 && !av[1][0]))
//         {
//             write (2, "Error\n", 6);
//             return 1;
//         }

//         char **args;
//         int i = 1; 
//         int j = 0;
//         int arg_count = 0;

//         int k = 1;
//         while (k < ac)
//         {
//             arg_count += count_word(av[k], ' ');
//             k++;
//         }

//         args = malloc((arg_count + 1) * sizeof(char *));
//         if (!args)
//             return 1;

//         i = 1;
//         while (i < ac)
//         {
//             if (ft_strchr(av[i], ' '))
//             {
//                 char **split_args = ft_split(av[i], ' ');
//                 if (!split_args)
//                     return 1;
                
//                 int k = 0;
//                 while (split_args[k])
//                 {
//                     args[j] = split_args[k];
//                     k++;
//                     j++;
//                 }
//             }
//             else
//             {
//                 args[j] = av[i];
//                 j++;
//             }
//             i++;
//         }
//         args[j] = NULL; // "    " ->nULL

//         stack_a(&a, args);

//         Node *current = a;
//         while (current != NULL)
//         {
//             printf("%d ", current->data);
//             current = current->next;
//         }
//         printf("\n");
//     }
// }

int main(int ac, char **av)
{
    if (ac > 1)
    {
        Node *a = NULL;
        char **nmber;
        int i;
        int j;
        int k;
        int count;

        count = 0;
        j = 0;
        k = 1;
        while (k < ac)
        {
            count += count_word(av[k], ' ');
            k++;
        }

        nmber = malloc((count + 1) * sizeof(char *));
        
        i = 1;
        while (i < ac)
        {
            if (ft_strchr(av[i], ' '))
            {
                char **split_args = ft_split(av[i], ' ');
                if (!split_args)
                    return 1;
                
                int k = 0;
                while (split_args[k])
                {
                    nmber[j] = split_args[k];
                    k++;
                    j++;
                }
            }
            else
            {
                nmber[j] = av[i];
                j++;
            }
            i++;
        }
        nmber[j] = NULL;
        stack_a(&a, nmber);

        Node *curr = a;
        while (curr != NULL)
        {
            printf ("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

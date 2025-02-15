#include "push_swap.h"

int ft_atoi(const char *s)
{
    int i;
    int rs;
    int sign;

    i = 0;
    rs = 0;
    sign = 1;
    while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        rs = rs * 10 + (s[i] - 48);
        if (rs * sign > INT_MAX)
            return (INT_MAX);
        if (rs * sign < INT_MIN)
            return (INT_MIN);
        i++;
    }
    return (rs * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int count_node(Node **head)
{
    int count = 0;
    while (*head != NULL)
    {
        count++;
        *head = (*head)->next;
    }
    return (count);
}

Node *find_last_node(Node *head)
{
    if (head == NULL)
        return (NULL);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    return (curr);
}

void cree_node(Node **head, int data)
{
    Node *last_node;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    else
    {
        last_node = find_last_node(*head);
        last_node->next = newNode;
        newNode->next = NULL;
    }
}

void free_list(Node **head)
{
    Node *curr = *head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

int repetition(Node *head, int nbr)
{
    if (head == NULL)
        return (0);
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == nbr)
            return (1);
        curr = curr->next;
    }
    return (0);
}
int is_string(char *str)
{
    return (str[0] == '"' && str[ft_strlen(str) - 1] == '"');
}

void stack_a(Node **head, char **av)
{
    int nbr;
    char **args;
    char **original_args; // To store the result of ft_split

    while (*av)  // Loop on each argument
    {
        if (is_string(*av))  // Check if it is a string (like "6 7 8 9")
        {
            args = ft_split(*av, ' ');
            original_args = args; // Save the result of split for later free
        }
        else
        {
            args = av; // Use the current argument directly
            av++;      // Move to the next argument in av
        }

        while (*args)  // Loop on the split arguments
        {
            nbr = ft_atoi(*args);
            if (repetition(*head, nbr)) // Check for duplicates
            {
                free_list(head);
                write(2, "Error\n", 6);
                exit(1);
            }
            cree_node(head, nbr); // Add the node
            args++; // Move to next split argument
        }

        if (is_string(*av))  // Only free if it was a split string
        {
            free(original_args); // Free the split arguments
        }
    }
}






// int main()
// {
//     Node *a = NULL;
//     Node *b = NULL;
//     char *av[] = {"3", "11", "4", "2", "9","1", NULL};
//     stack_a(&a, av);

//     // rra(&a);
//     // pb(&a, &b);

//     printf ("%d\n", count_node(&a));

//     Node *curr = a;
//     while (curr != NULL)
//     {
//         printf("%d ", curr->data);
//         curr = curr->next;
//     }

//     // printf("\n");

//     Node *curr1 = b;
//     while (curr1 != NULL)
//     {
//         printf("%d ", curr1->data);
//         curr1 = curr1->next;
//     }
//     // printf("\n");
//     free_list(&a);
//     free_list(&b);

//     return 0;
// }
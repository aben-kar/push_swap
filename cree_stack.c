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
    if (!newNode) {
        write(2, "Memory allocation failed\n", 25);
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        last_node = find_last_node(*head);
        last_node->next = newNode;
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

void stack_a(Node **head, char **av)
{
    int nbr;
    // int i = 0;
    while (*av)
    {
        // printf("Processing argument: %s\n", *av); 
        nbr = ft_atoi(*av);
        // printf("Converted number: %d\n", nbr);
        if (repetition(*head, nbr))
        {
            free_list(head);
            write(2, "Error\n", 6);
            exit(1);
        }
        cree_node(head, nbr);
        av++;
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
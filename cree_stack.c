#include "push_swap.h"

int ft_atoi(const char *s)
{
    int i = 0;
    long rs = 0;
    int sign = 1;

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
        rs = rs * 10 + (s[i] - '0');

        if ((rs * sign) > INT_MAX || (rs * sign) < INT_MIN)
            write (2, "Error\n", 6);
        i++;
    }
    if (s[i] != '\0')
        write (2, "Error\n", 6);
    return (rs * sign);
}

int count_node(Node **head)
{
    int count = 0;
    Node *curr = *head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
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

void cree_node(Node **head, int data)
{
    Node *last_node;
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        write (2, "Error\n", 6);
        free_list(head);
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
        *head = newNode;
    else
    {
        last_node = find_last_node(*head);
        last_node->next = newNode;
    }
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

int stack_a(Node **head, char **av)
{
    int nbr;
    while (*av)
    {
        nbr = ft_atoi(*av);
        if (!nbr)
        {
            // write (2, "Error\n", 6);
            free_list(head);
            return 1;
        }
        else if (repetition(*head, nbr))
        {
            write (2, "ana\n", 4);
            free_list(head);
            write(2, "E2rror\n", 7);
            return (2);
        }
        cree_node(head, nbr);
        av++;
    }
    return (0);
}

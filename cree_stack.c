#include "push_swap.h"

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

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

        // Check for overflow
        if (rs * sign > INT_MAX)
            return INT_MAX;
        if (rs * sign < INT_MIN)
            return INT_MIN;

        i++;
    }

    if (s[i] != '\0')
    {
        write(2, "Error\n", 6);
        exit(1);
    }

    return (int)(rs * sign);
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
        nbr = ft_atoi(*av);
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

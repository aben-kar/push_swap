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
        {
            write (2, "MAX_INT-->Error\n", 16);
            return (-1);
        }
        i++;
    }
    if (s[i] != '\0')
    {
        write (2, "Alpha-->Error\n", 14);
        return (-1);
    }
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

int cree_node(Node **head, int data)
{
    Node *last_node;
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        free(newNode);
        free_list(head);
        return 1;
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
    return (0);
}


int repetition(Node **head, int nbr)
{
    if (head == NULL)
        return (0);
    Node *curr = *head;
    while (curr != NULL)
    {
        if (curr->data == nbr)
            return (1);
        curr = curr->next;
    }
    return (0);
}

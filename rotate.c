#include "push_swap.h"

void ra(Node **head)
{
    Node *tmp = *head;
    Node *tmp1 = tmp->next;
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    tmp->next = NULL;
    *head = tmp1;
}
void rb(Node **head)
{
    Node *tmp = *head;
    Node *tmp1 = tmp->next;
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    tmp->next = NULL;
    *head = tmp1;
}

void rr(Node **head_a, Node **head_b)
{
    ra(head_a);
    rb(head_b);
}
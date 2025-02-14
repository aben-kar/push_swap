#include "push_swap.h"

void rra(Node **head)
{
    Node *tmp;
    Node *prev;
    Node *curr;

    prev = NULL;
    tmp = *head;
    curr = *head;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    curr->next = tmp;
    *head = curr;
}
void rrb(Node **head)
{
    Node *tmp;
    Node *prev;
    Node *curr;

    prev = NULL;
    tmp = *head;
    curr = *head;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    curr->next = tmp;
    *head = curr;
}

void rrr(Node **head_a, Node **head_b)
{
    rra(head_a);
    rra(head_b);
}
#include "push_swap.h"

void sa(Node **head)
{
    if (!*head || !(*head)->next)
        return;
    int tmp;
    Node *curr = *head;

    tmp = curr->data;
    curr->data = curr->next->data;
    curr->next->data = tmp;
}
void sb(Node **head)
{
    if (!*head || !(*head)->next)
        return;
    int tmp;
    Node *curr = *head;

    tmp = curr->data;
    curr->data = curr->next->data;
    curr->next->data = tmp;
}
void ss(Node **head_a, Node **head_b)
{
    sa(head_a);
    sb(head_b);
}
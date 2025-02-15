#include "push_swap.h"

void pa(Node **head_a, Node **head_b) {
    if (*head_b == NULL)
        return;

    Node *tmp = *head_b;
    *head_b = (*head_b)->next;

    tmp->next = *head_a;
    *head_a = tmp;
}

void pb(Node **head_a, Node **head_b) {
    if (*head_a == NULL)
        return;

    Node *tmp = *head_a;
    *head_a = (*head_a)->next;

    tmp->next = *head_b;
    *head_b = tmp;
}
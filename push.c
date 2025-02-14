#include "push_swap.h"

void pa(Node **head_a, Node **head_b)// hez mn b ou het f a
{
    Node *tmp;

    if (*head_b == NULL) 
        return;

    tmp = *head_b;
    *head_b = (*head_b)->next;

    tmp->next = NULL;
    if (*head_a == NULL) {
        *head_a = tmp;
    } 
    else {
        Node *last = *head_a;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = tmp;
    }
}

void pb(Node **head_a, Node **head_b) // hez mn a ou het f b
{
    Node *tmp;

    if (*head_a == NULL) 
        return;

    tmp = *head_a;
    *head_a = (*head_a)->next;

    tmp->next = NULL;
    if (*head_b == NULL) {
        *head_b = tmp;
    }
    else {
        Node *last = *head_b;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = tmp;
    }
}
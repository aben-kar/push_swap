#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *cree_node(int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}
Node *last_node(Node *head, int data) // "ADD LAST NODE IN LIKED LIST"
{
    if (head == NULL)
        return (NULL);
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            Node *n_node = malloc(sizeof(Node));
            n_node->data = data;
            n_node->next = NULL;
            curr->next = n_node;
            break;
        }
        curr = curr->next;
    }
    return (head);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    Node* head = cree_node(2);
    head->next = cree_node(3);
    head->next->next = cree_node(5);
    head->next->next->next = cree_node(6);

    head = last_node(head, 12);

    printList(head);
}

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

Node *add_node_after_node(Node *head, int data, int key) // "ADD NODE AFTER NODE"
{
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("Makayenach Node\n");
        return (NULL);
    }

    Node *n_node = malloc(sizeof(Node));
    n_node->data = data;
    n_node->next = curr->next;
    curr->next = n_node;

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
    Node *head = cree_node(1);
    head->next = cree_node(2);
    head->next->next = cree_node(3);
    head->next->next->next = cree_node(4);
    head->next->next->next->next = cree_node(5);

    add_node_after_node(head, 12, 2);

    printList(head);

    while (head != NULL)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }
}
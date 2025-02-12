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

Node *position_node(Node *head, int data, int posistion) // "ADD NODE ANY POSITION"
{
    if (head == NULL)
        return (NULL);
    if (posistion == 0)
    {
        Node *n_node = malloc(sizeof(Node));
        n_node->data = data;
        n_node->next = head;
        return (n_node);
    }

    int i = 0;
    Node *curr = head;
    while (i < posistion - 1 && curr != NULL)
    {
        curr = curr->next;
        i++;
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

    head = position_node(head, 12, 2);

    printList(head);

    while (head != NULL)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }
}
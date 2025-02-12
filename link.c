#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node  *createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *first_node(Node *head, int data) // "ADD FIRST NODE"
{
    Node *n_node = malloc(sizeof(Node));
    n_node->data = data;
    n_node->next = head;
    return (n_node);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {

    Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(6);

    head = first_node(head, 12);

    printList(head);

    while (head != NULL)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}

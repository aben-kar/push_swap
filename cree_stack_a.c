#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

int ft_atoi(const char *s)
{
    int i;
    int rs;
    int sign;

    i = 0;
    rs = 0;
    sign = 1;
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
        rs = rs * 10 + (s[i] - 48);
        if (rs * sign > INT_MAX)
            return (INT_MAX);
        if (rs * sign < INT_MIN)
            return (INT_MIN);
        i++;
    }
    return (rs * sign);
}

Node *find_last_node(Node *head)
{
    if (head == NULL)
        return (NULL);
    while (head->next != NULL)
    {
        head = head->next;
    }
    return (head);
}

void cree_node(Node **head, int data)
{
    Node *last_node;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    else
    {
        last_node = find_last_node(*head);
        last_node->next = newNode;
        newNode->next = NULL;
    }
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

int repetition(Node *head, int nbr)
{
    while (head != NULL)
    {
        if (head->data == nbr)
            return (1);
        head = head->next;
    }
    return (0);
}

void stack_a(Node **head, char **av)
{
    int nbr;
    while (*av)
    {
        nbr = ft_atoi(*av);
        if (repetition(*head, nbr))
        {
            free_list(head);
        }
        cree_node(head, nbr);
        av++;
    }
}

int main()
{
    Node *a = NULL;
    char *av[] = {"42", "12", "11", NULL}; // Correct initialization of `av`

    stack_a(&a, av);

    // Print the list
    Node *curr = a;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Free the list
    free_list(&a);

    return 0;
}
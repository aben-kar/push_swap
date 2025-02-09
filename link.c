# include <stdio.h>
# include <stdlib.h>


typedef struct s_node {
    int data;
    struct s_node *next;
} my_node;


void cree_node(my_node **head, int data1)
{
    my_node *nwnode;
    nwnode = malloc(sizeof(my_node));
    if (!nwnode)
        return;
    nwnode->data = data1;
    nwnode->next = NULL;
    if (*head == NULL) 
    {
        *head = nwnode;  // Si la liste est vide
    } 
    else 
    {
        my_node *tmp = *head;
        while (tmp->next)
            tmp = tmp->next;  
        tmp->next = nwnode; // Ajouter à la fin
    }
}
void printlist(my_node *head)
{
    while (head)
    {
        printf("--> %d\n", head->data);
        head = head->next; 
    }
}

int main()
{
    my_node *head = NULL; 

    cree_node(&head, 12);
    cree_node(&head, 11);
    cree_node(&head, 16);
    cree_node(&head, 18);
    cree_node(&head, 19);
    cree_node(&head, 15);

    printlist(head);
}
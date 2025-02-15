#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h> 

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

// Push a an b
void pa(Node **head_a, Node **head_b);
void pb(Node **head_a, Node **head_b);
// Reverse rotate a and b
void rra(Node **head);
void rrb(Node **head);
void rrr(Node **head_a, Node **head_b);
// Rotate a and b
void ra(Node **head);
void rb(Node **head);
void rr(Node **head_a, Node **head_b);
// Swap a and b
void sa(Node **head);
void sb(Node **head);
void ss(Node **head_a, Node **head_b);
//////////////////////////////////////
void stack_a(Node **head, char **av);
char	**ft_split(char const *s, char c);
void free_list(Node **head);
int count_word(const char *s1, char sp);
char **parse_arguments(int ac, char **av);
char	*ft_strchr(const char *str, int c);
void printList(Node* node);

#endif
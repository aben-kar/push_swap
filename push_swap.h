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
char	**ft_split(char const *s, char c);
void free_list(Node **head);
int	count_word(char const *s1, char sp);
Node *parse_arguments(int ac, char **av);
char	*ft_strchr(const char *str, int c);
void printList(Node* node);
int is_only_spaces(const char *str);
void	ft_free(char **prr);
void *ft_calloc(size_t count, size_t size);
int cree_node(Node **head, int data);
int ft_atoi(const char *s);
int repetition(Node **head, int nbr);
int	ft_isdigit(int c);
int print_error(char *msg);
int write_error(char *msg);

#endif
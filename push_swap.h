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
int stack_a(Node **head, Node *av);
char	**ft_split(char const *s, char *c);
void free_list(Node **head);
int	count_word(char const *s1, char *sp);
Node *parse_arguments(int ac, char **av);
char	*ft_strchr(const char *str, int c);
void printList(Node* node);
int is_only_spaces(const char *str);
void	ft_free(char **prr);
char	*ft_strdup(const char *s1);
void *ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int cree_node(Node **head, int data);
int ft_atoi(const char *s);

#endif
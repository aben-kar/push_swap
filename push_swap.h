/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:58:56 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/20 19:06:48 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>

typedef struct node
{
	int				data;
	struct node		*next;
}	t_Node;

typedef struct variable
{
	int		j;
	int		i;
	char	**prr;
	int		len_word;
	char	**split_args;
	int		k;
	long	num;
	long	rs;
	int		sign;
	char	*result;
}	t_push_swap;

void	pa(t_Node **head_a, t_Node **head_b);
void	pb(t_Node **head_a, t_Node **head_b);
void	rra(t_Node **head);
void	rrb(t_Node **head);
void	rrr(t_Node **head_a, t_Node **head_b);
void	ra(t_Node **head);
void	rb(t_Node **head);
void	rr(t_Node **head_a, t_Node **head_b);
void	sa(t_Node **head);
void	sb(t_Node **head);
void	ss(t_Node **head_a, t_Node **head_b);
char	**ft_split(char const *s, char c);
void	free_list(t_Node **head);
t_Node	*parse_arguments(int ac, char **av);
char	*ft_strchr(const char *str, int c);
void	printlist(t_Node *node);
int		is_only_spaces(const char *str);
void	ft_free(char **prr);
void	*ft_calloc(size_t count, size_t size);
int		cree_node(t_Node **head, int data);
long	ft_atoi(const char *s);
int		repetition(t_Node **head, int nbr);
int		ft_isdigit(int c);
long	print_error(char *msg);
int		write_error(char *msg);
int		ft_strlen(const char *s);
int		only_tab(const char *str);
int		ft_isspace(char c);
int		count_node(t_Node **head);
void two_nbr(t_Node **head);
void three_nbr(t_Node **head_a);
void four_nbr(t_Node **head_a, t_Node **head_b);
void five_nbr(t_Node **head_a, t_Node **head_b);
int find_min_position(t_Node *head);
void move_min_to_top(t_Node **head, int min_pos);
void move_min_to_top1(t_Node **head, int min_pos);
int	is_sorted(t_Node *head);

#endif

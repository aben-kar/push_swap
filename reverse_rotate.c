/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:28:28 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/18 20:26:25 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_Node **head)
{
	t_Node	*tmp;
	t_Node	*prev;
	t_Node	*curr;

	prev = NULL;
	tmp = *head;
	curr = *head;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	curr->next = tmp;
	*head = curr;
	write (1, "rra\n", 4);
}

void	rrb(t_Node **head)
{
	t_Node	*tmp;
	t_Node	*prev;
	t_Node	*curr;

	prev = NULL;
	tmp = *head;
	curr = *head;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	curr->next = tmp;
	*head = curr;
	write (1, "rrb\n", 4);
}

void	rrr(t_Node **head_a, t_Node **head_b)
{
	rra(head_a);
	rra(head_b);
	write (1, "rrr\n", 4);
}

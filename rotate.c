/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:30:39 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/18 14:01:51 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_Node **head)
{
	t_Node	*tmp;
	t_Node	*tmp1;
	t_Node	*last;

	tmp = *head;
	tmp1 = tmp->next;
	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
	*head = tmp1;
}

void	rb(t_Node **head)
{
	t_Node	*tmp;
	t_Node	*tmp1;
	t_Node	*last;

	tmp = *head;
	tmp1 = tmp->next;
	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
	*head = tmp1;
}

void	rr(t_Node **head_a, t_Node **head_b)
{
	ra(head_a);
	rb(head_b);
}

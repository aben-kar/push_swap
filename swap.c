/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:50 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/18 14:02:02 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_Node **head)
{
	int		tmp;
	t_Node	*curr;

	if (!*head || !(*head)->next)
		return ;
	curr = *head;
	tmp = curr->data;
	curr->data = curr->next->data;
	curr->next->data = tmp;
}

void	sb(t_Node **head)
{
	int		tmp;
	t_Node	*curr;

	if (!*head || !(*head)->next)
		return ;
	curr = *head;
	tmp = curr->data;
	curr->data = curr->next->data;
	curr->next->data = tmp;
}

void	ss(t_Node **head_a, t_Node **head_b)
{
	sa(head_a);
	sb(head_b);
}

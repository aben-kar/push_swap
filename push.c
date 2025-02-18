/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:27:10 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/18 14:01:28 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_Node **head_a, t_Node **head_b)
{
	t_Node	*tmp;

	if (*head_b == NULL)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = *head_a;
	*head_a = tmp;
}

void	pb(t_Node **head_a, t_Node **head_b)
{
	t_Node	*tmp;

	if (*head_a == NULL)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = *head_b;
	*head_b = tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:28:50 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/24 22:29:40 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_Node **head)
{
	t_Node	*current;
	int		max;

	if (*head == NULL)
		return (0);
	max = (*head)->data;
	current = *head;
	while (current != NULL)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

int	find_max_index(t_Node **head)
{
	int		max;
	int		index;
	int		max_index;
	t_Node	*current;

	if (*head == NULL)
		return (0);
	max = find_max(head);
	index = 0;
	max_index = 0;
	current = *head;
	while (current != NULL)
	{
		if (current->data == max)
			max_index = index;
		current = current->next;
		index++;
	}
	return (max_index);
}

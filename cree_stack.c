/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cree_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:13:07 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/18 14:03:18 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_node(t_Node **head)
{
	int		count;
	t_Node	*curr;

	count = 0;
	curr = *head;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

t_Node	*find_last_node(t_Node *head)
{
	t_Node	*curr;

	if (head == NULL)
		return (NULL);
	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	free_list(t_Node **head)
{
	t_Node	*curr;
	t_Node	*next;

	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

int	cree_node(t_Node **head, int data)
{
	t_Node	*last_node;
	t_Node	*new_node;

	new_node = malloc(sizeof(t_Node));
	if (!new_node)
	{
		free_list(head);
		return (1);
	}
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = find_last_node(*head);
		last_node->next = new_node;
	}
	return (0);
}

int	repetition(t_Node **head, int nbr)
{
	t_Node	*curr;

	if (head == NULL)
		return (0);
	curr = *head;
	while (curr != NULL)
	{
		if (curr->data == nbr)
			return (1);
		curr = curr->next;
	}
	return (0);
}

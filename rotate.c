/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:30:39 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/24 18:17:27 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_Node **head)
{
	if (*head == NULL || (*head)->next == NULL)
        return;
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
	write (1, "ra\n", 3);
}

void rb(t_Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; 

    t_Node *tmp;
    t_Node *tmp1;
    t_Node *last;

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
    write(1, "rb\n", 3);
}

void	rr(t_Node **head_a, t_Node **head_b)
{
	ra(head_a);
	rb(head_b);
	write (1, "rr\n", 3);
}

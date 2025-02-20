/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_five_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:21:10 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/20 19:21:11 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_position(t_Node *head)
{
    int min = head->data;
    int pos = 0;
    int i = 0;

    while (head)
    {
        if (head->data < min)
        {
            min = head->data;
            pos = i;
        }
        head = head->next;
        i++;
    }
    return pos;
}

void move_min_to_top(t_Node **head, int min_pos)
{
    if (min_pos == 0)
        return ;
    if (min_pos == 1)
        sa(head);
    else if (min_pos == 2)
    {
        ra(head);
        sa(head);
    }
    else if (min_pos == 3)
        rra(head);
}

void move_min_to_top1(t_Node **head, int min_pos)
{
    if (min_pos == 0)
        return ;
    if (min_pos == 1)
        sa(head);
    else if (min_pos == 2)
    {
        ra(head);
        sa(head);
    }
    else if (min_pos == 3)
    {
        rra(head);
        rra(head);
    }
    else if (min_pos == 4)
        rra(head);
}

int	is_sorted(t_Node *head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

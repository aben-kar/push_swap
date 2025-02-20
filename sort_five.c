/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:21:00 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/20 19:21:01 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void two_nbr(t_Node **head_a)
{
    if ((*head_a)->data > (*head_a)->next->data)
    {
        sa(head_a);
    }
}
void three_nbr(t_Node **head_a)
{
    if (((*head_a)->data > (*head_a)->next->data)
        && ((*head_a)->data > (*head_a)->next->next->data))
        ra(head_a);
    if (((*head_a)->data > (*head_a)->next->data)
        && ((*head_a)->data < (*head_a)->next->next->data))
        sa(head_a);
    if (((*head_a)->data < (*head_a)->next->data)
        && ((*head_a)->data < (*head_a)->next->next->data)
        && ((*head_a)->next->data > (*head_a)->next->next->data))
        rra(head_a);
    if (((*head_a)->data < (*head_a)->next->data)
        && ((*head_a)->data > (*head_a)->next->next->data))
        rra(head_a);
    if ((*head_a)->data > (*head_a)->next->data)
        sa(head_a);
}

void four_nbr(t_Node **head_a, t_Node **head_b)
{
    if (is_sorted(*head_a) == 1)
        return;

    int min_pos;
    min_pos = find_min_position(*head_a);
    move_min_to_top(head_a, min_pos);
    pb(head_a, head_b);

    three_nbr(head_a);

    pa(head_a, head_b);
}

void five_nbr(t_Node **head_a, t_Node **head_b)
{
    if (is_sorted(*head_a) == 1)
        return;

    int min_pos;
    min_pos = find_min_position(*head_a);
    move_min_to_top1(head_a, min_pos);
    pb(head_a, head_b);

    four_nbr(head_a, head_b);

    pa(head_a, head_b);
}

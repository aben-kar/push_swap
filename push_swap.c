/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:55:08 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/24 21:36:56 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_with_rotate(t_Node **a, t_Node **b, int *tmp_i)
{
	pb(a, b);
	rb(b);
	(*tmp_i)++;
}

void	push_without_rotate(t_Node **a, t_Node **b, int *tmp_i)
{
	pb(a, b);
	(*tmp_i)++;
}

void	pushing_sb(t_Node **a, t_Node **b)
{
	int		size;
	int		*arr;
	int		range;
	int		tmp_i;
	int		pos;

	size = count_node(a);
	if (size == 0 || size == 1)
		return ;
	arr = store_in_array(*a, size);
	sort_array(arr, size);
	range = get_range(size);
	tmp_i = 0;
	while (*a != NULL)
	{
		pos = find_position(arr, size, (*a)->data);
		if (pos <= tmp_i)
			push_with_rotate(a, b, &tmp_i);
		else if (pos <= tmp_i + range)
			push_without_rotate(a, b, &tmp_i);
		else
			ra(a);
	}
	free(arr);
}

void	move_max_to_top(t_Node **b, int index, int size)
{
	int	i;
	int	j;

	if (index > size)
	{
		i = count_node(b) - 1;
		while (i >= index)
		{
			rrb(b);
			i--;
		}
	}
	else
	{
		j = 0;
		while (j < index)
		{
			rb(b);
			j++;
		}
	}
}

void	sort_sa(t_Node **a, t_Node **b)
{
	t_Node	*tmp;
	int		size;
	int		index;

	tmp = *b;
	while (tmp->next != NULL)
	{
		size = count_node(b) / 2;
		index = find_max_index(b);
		move_max_to_top(b, index, size);
		pa(a, b);
		tmp = *b;
	}
	pa(a, b);
}

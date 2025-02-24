/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_stack_b_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:12:27 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/24 21:44:38 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*store_in_array(t_Node *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	return (arr);
}

void	sort_array(int *tab, int size)
{
	int	swp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swp = tab[j];
				tab[j] = tab[i];
				tab[i] = swp;
			}
			j++;
		}
		i++;
	}
}

int	find_position(int *sorted_arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	get_range(int size)
{
	if (size <= 10)
		return (5);
	else if (size <= 100)
		return (13);
	else
		return (30);
}

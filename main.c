/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:08:59 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/24 22:28:44 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_Node	*a;
	t_Node	*b;

	if (ac > 1)
	{
		b = NULL;
		a = parse_arguments(ac, av);
		if (!a)
		{
			free_list(&a);
			return (1);
		}
		if (count_node(&a) == 2)
			two_nbr(&a);
		if (count_node(&a) == 3)
			three_nbr(&a);
		if (count_node(&a) == 4)
			four_nbr(&a, &b);
		if (count_node(&a) == 5)
			five_nbr(&a, &b);
		if (count_node(&a) > 5)
			(pushing_sb(&a, &b), sort_sa(&a, &b));
		free_list(&a);
		free_list(&b);
	}
}

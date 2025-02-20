/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:08:59 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/20 16:20:25 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        t_Node *a;
        t_Node *b = NULL;     
        a = parse_arguments(ac, av);
        // b = parse_arguments(ac, av);
        if (!a)
        {
            free_list(&a);
            return (1);
        }
        
        if (count_node(&a) == 2) // sort 2 number in my stack a.
        {
            two_nbr(&a);
        }

        if (count_node(&a) == 3) // sort 3 number in my stack a.
        {
            three_nbr(&a);
        }
        
        if (count_node(&a) == 4) // sort 4 number in my stack a.
        {
            four_nbr(&a, &b);
        }

        if (count_node(&a) == 5) // sort 5 number in my stack a.
        {
            five_nbr(&a, &b);
        }
        

        // printlist(a);
        // printlist(b);

        free_list(&a);
        free_list(&b);
    }
}
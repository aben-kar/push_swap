/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:08:59 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/18 14:09:59 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        t_Node *a;
        // Node *b = NULL;     
        a = parse_arguments(ac, av);
        if (!a)
        {
            free_list(&a);
            return (1);
        }      
        // pb(&a, &b);
        // pb(&a, &b);
        // sa(&a);
        // sb(&b);
        // pa(&a, &b);
        // pa(&a, &b);

        printlist(a);
        // printList(b);

        free_list(&a);
        // free_list(&b);
    }
}
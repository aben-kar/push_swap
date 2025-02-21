/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:12:27 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/21 17:13:05 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_node_1(t_Node *head)
{
    int count = 0;
    t_Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
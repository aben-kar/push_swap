/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:55:08 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/23 16:02:19 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *store_in_array(t_Node *a, int size)
{
    int *arr = malloc(size * sizeof(int));
    if (!arr)
        return NULL;

    int i = 0;
    while (a)
    {
        arr[i] = a->data;
        a = a->next;
        i++;
    }
    return arr;
}

void sort_array(int *tab, int size)
{
    int swp;
    int i = 0;
    int j;

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

int find_position(int *sorted_arr, int size, int value)
{
    int i = 0;
    while (i < size)
    {
        if (sorted_arr[i] == value)
            return i;
        i++;
    }
    return -1;
}

void sort_stack(t_Node **a, t_Node **b)
{
    int size = count_node(a);
    if (size == 0)
        return ;
    int *arr = store_in_array(*a, size);
    sort_array(arr, size);

    int range;

    if (size <= 10)
    {
        write (2, "ana\n", 4);
        range = 5;
    }
    else if (size <= 100)
    {
        write (2, "ana1\n", 5);
        range = 13;
    }
    else if (size > 100)
        range = 30;
        
    int tmp_i = 0;
    
    while (*a != NULL) 
    {
        t_Node *current = *a;
        while (current != NULL)
        {
            int pos = find_position(arr, size, current->data);

            if (pos <= tmp_i)
            {
                pb(a, b);
                rb(b);
                tmp_i++;
                current = *a;
            }
            else if (pos <= tmp_i + range)
            {
                pb(a, b);
                current = *a;
                tmp_i++;
            }
            else if (pos > range)
            {
                current = current->next;
                int size1 = count_node(current) / 2;
                if ((pos <= tmp_i) || (pos <= tmp_i + range))
                {
                    if (pos < size)
                        
                }
                
            }
        }
    }
}

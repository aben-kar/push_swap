/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:55:08 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/22 15:12:46 by acben-ka         ###   ########.fr       */
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
    int swapped;

    while (i < size)
    {
        swapped = 0;
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                swp = tab[j];
                tab[j] = tab[i];
                tab[i] = swp;
                swapped = 1;
            }
            j++;
        }
        if (swapped == 0)
            break;
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
    int *arr = store_in_array(*a, size);
    sort_array(arr, size);

    int range = 5;
    int tmp_i = 0;
    
    t_Node *current = *a;
    while (current)
    {
        int pos = find_position(arr, size, current->data);
        
        if (pos <= tmp_i)
        {
            pb(a, b);
            rb(b);
            current = current->next;
        }
        else if (pos >= tmp_i && pos <= range)
        {
            pb(a, b);
            current = current->next;
        }
        else if (pos > range)
            current = current->next;
        tmp_i++;
    }
}



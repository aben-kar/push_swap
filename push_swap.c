/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:55:08 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/23 19:23:27 by acben-ka         ###   ########.fr       */
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
    // int size = count_node(a);
    int range;
    if (size <= 10)
        range = 5;
    else if (size <= 100)
        range = 13;
    else
        range = 30;
        
    int tmp_i = 0;
    
    t_Node *current = *a;
    while (current != NULL)
    {
        // int size = count_node(a);
        // if (size == 0)
        //     return ;
    
        // int *arr = store_in_array(*a, size);
        // sort_array(arr, size);
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
            tmp_i++;
            current = *a;
        }

        else
        {
            // current = current->next;
            t_Node *next = current->next;
            int found = 0;
            t_Node *tmp = NULL;
            // int best_pos = size;

            while (next)
            {
                int new_pos = find_position(arr, size, next->data);
                        
                if (new_pos <= tmp_i || new_pos <= tmp_i + range)
                {
                    found = 1;
                    tmp = next;
                    // best_pos = pos;
                }
                next = next->next;
            }

            if (found && tmp)
            {
                int new_pos1 = find_position(arr, size, tmp->data);
                if (new_pos1 < size / 2)
                {
                    int i = 0;
                    while (i < new_pos1)
                    {
                        ra(a);
                        i++;
                    }
                }
                else if (new_pos1 > size / 2)
                {
                    int j = count_node(a) - 1;
                    while (j >= new_pos1)
                    {
                        rra(a);
                        j--;
                    }
                }
                pb(a, b);
                tmp_i++;
                current = *a;
            }
        // tmp_i++;
        // current = *a;
        }
        // free(arr);
    }

}


//  if (pos <= tmp_i) || if (pos <= tmp_i + range) || if (pos > range)
//
// range = 24
// tmp_i = 11

// 1 2 3 4 5 6 7 9 11 13 14 15 16
// 0 1 2 3 4 5 6 7 8  9  10 11 12

/*
13 9
16 12
*/


/*
9
7
15
5
6
4
3
1
2
11
14
13
16
*/
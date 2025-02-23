/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:55:08 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/23 22:05:44 by acben-ka         ###   ########.fr       */
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

void sort_sb(t_Node **a, t_Node **b)
{
    int size = count_node(a);
    if (size == 0 || size == 1)
        return;
    
    int *arr = store_in_array(*a, size);
    sort_array(arr, size);
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
            t_Node *next = current->next;
            int found = 0;
            t_Node *tmp = NULL;
            int best_pos = size;

            while (next)
            {
                int new_pos = find_position(arr, size, next->data);
                        
                if (new_pos <= tmp_i || new_pos <= tmp_i + range)
                {
                    found = 1;
                    tmp = next;
                    best_pos = pos;
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
        }
    }
    free(arr);
}

int find_max(t_Node **head)
{
    if (*head == NULL)
        return 0;
    
    int max = (*head)->data;
    t_Node *current = *head;
    while (current != NULL)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

int find_max_index(t_Node **head)
{
    if (*head == NULL)
        return 0;

    int max = find_max(head);
    int index = 0;
    int max_index = 0;
    t_Node *current = *head;

    while (current != NULL)
    {
        if (current->data == max)
            max_index = index;
        current = current->next;
        index++;
    }
    return max_index;
}

void sort_sa(t_Node **a, t_Node **b)
{
    t_Node *tmp = *b;
    
    while (tmp != NULL && tmp->next != NULL)
    {
        int size = count_node(b) / 2;
        int index = find_max_index(b);

        if (index > size)
        {
            int i = count_node(b) - 1;
            while (i >= index)
            {
                rrb(b);
                i--;
            }
            pa(a, b);
        }
        else
        {
            int j = 0;
            while (j < index)
            {
                rb(b);
                j++;
            }
            pa(a, b);
        }
        tmp = *b;
    }
    if (tmp != NULL)
        pa(a, b);
}

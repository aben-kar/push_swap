#include "push_swap.h"

int	is_sorted(t_Node *head)
{
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void two_nbr(t_Node **head_a)
{
    if ((*head_a)->data > (*head_a)->next->data)
    {
        sa(head_a);
    }
}
void three_nbr(t_Node **head_a)
{
    if (((*head_a)->data > (*head_a)->next->data) && ((*head_a)->data > (*head_a)->next->next->data))
        ra(head_a);
    if (((*head_a)->data > (*head_a)->next->data) && ((*head_a)->data < (*head_a)->next->next->data))
        sa(head_a);
    if (((*head_a)->data < (*head_a)->next->data) && ((*head_a)->data < (*head_a)->next->next->data) && ((*head_a)->next->data > (*head_a)->next->next->data))
        rra(head_a);
    if (((*head_a)->data < (*head_a)->next->data) && ((*head_a)->data > (*head_a)->next->next->data))
        rra(head_a);
    if ((*head_a)->data > (*head_a)->next->data)
        sa(head_a);
}
void four_nbr(t_Node **head_a, t_Node **head_b)
{
    if (is_sorted(*head_a) == 1)
		return;
    pb(head_a, head_b);
	three_nbr(head_a);
    if (((*head_b)->data > (*head_a)->next->next->data))
    {
        pa(head_a, head_b);
        ra(head_a);
    }
    if(((*head_b)->data > (*head_a)->data) && ((*head_b)->data < (*head_a)->next->data))
    {
        pa(head_a, head_b);
        sa(head_a);
    }
    if(((*head_b)->data > (*head_a)->next->data) && ((*head_b)->data < (*head_a)->next->next->data))
    {
        ra(head_a);
        ra(head_a);
        pa(head_a, head_b);
        rra(head_a);
        rra(head_a);
    }
    if(((*head_b)->data < (*head_a)->data) && ((*head_b)->data < (*head_a)->next->next->data))
        pa(head_a, head_b);
}

// void five_nbr(t_Node **head_a, t_Node **head_b)
// {
//     if (is_sorted(*head_a) == 1)
// 		return;
//     pb(head_a, head_b);
// 	four_nbr(head_a, head_b);

//     if (((*head_b)->data > (*head_a)->data) && ((*head_b)->data > (*head_a)->next->next->next->data))
//     {
//         pa(head_a, head_b);
//         ra(head_a);
//     }
//     if (((*head_b)->data > (*head_a)->data) && ((*head_b)->data < (*head_a)->next->data))
//     {
//         ra(head_a);
//         pa(head_a, head_b);
//         rra(head_a);
//     }
//     if (((*head_b)->data > (*head_a)->next->data) && ((*head_b)->data < (*head_a)->next->next->data))
//     {
//         ra(head_a);
//         ra(head_a);
//         pa(head_a, head_b);
//         rra(head_a);
//         rra(head_a);
//     }
//     if (((*head_b)->data > (*head_a)->next->next->data) && ((*head_b)->data < (*head_a)->next->next->next->data))
//     {
//         ra(head_a);
//         ra(head_a);
//         ra(head_a);
//         pa(head_a, head_b);
//         rra(head_a);
//         rra(head_a);
//         rra(head_a);
//     }
//     if (((*head_b)->data < (*head_a)->data) && ((*head_b)->data < (*head_a)->next->next->next->data))
//         pa(head_a, head_b);
// }

t_Node *find_min_node(t_Node **head)
{
    if (!*head)
        return 0;  // Empty list

    t_Node *current;
    t_Node *min_value;

    min_value = *head;
    current = (*head)->next;

    while (current != NULL)
    {
        if (current->data < min_value->data)
            min_value = current;
        current = current->next;
    }
    return min_value;  // Return the minimum value
}


void five_nbr(t_Node **head_a, t_Node **head_b)
{
    if (is_sorted(*head_a) == 1)
		return;
    t_Node *min = find_min_node(head_a);


    // if (is_sorted(*head_b) == 1)
    // {
    //     pa(head_a, head_b);
    //     pa(head_a, head_b);
    // }

    if ((*head_b)->data > (*head_b)->next->data)
    {
        pa(head_a, head_b);
        pa(head_a, head_b);
    }
    
    if ((*head_b)->data < (*head_b)->next->data)
    {
        sb(head_b);
        pa(head_a, head_b);
        pa(head_a, head_b);
    }
}

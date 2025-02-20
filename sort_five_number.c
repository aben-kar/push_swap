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
int find_min_position(t_Node *head)
{
    int min = head->data;
    int pos = 0;
    int i = 0;

    while (head)
    {
        if (head->data < min)
        {
            min = head->data;
            pos = i;
        }
        head = head->next;
        i++;
    }
    return pos;
}

void move_min_to_top(t_Node **head, int min_pos)
{
    if (min_pos == 0)
        return ;
    if (min_pos == 1)
        sa(head);
    else if (min_pos == 2)
    {
        ra(head);
        sa(head);
    }
    else if (min_pos == 3)
        rra(head);
}

void four_nbr(t_Node **head_a, t_Node **head_b)
{
    if (is_sorted(*head_a))
        return;

    int min_pos;
    min_pos = find_min_position(*head_a);
    move_min_to_top(head_a, min_pos);
    pb(head_a, head_b);

    three_nbr(head_a);

    pa(head_a, head_b);
}

void move_min_to_top1(t_Node **head, int min_pos)
{
    if (min_pos == 0)
        return ;
    if (min_pos == 1)
        sa(head);
    else if (min_pos == 2)
    {
        ra(head);
        sa(head);
    }
    else if (min_pos == 3)
    {
        rra(head);
        rra(head);
    }
    else if (min_pos == 4)
        rra(head);
}
void five_nbr(t_Node **head_a, t_Node **head_b)
{
    if (is_sorted(*head_a))
        return;

    int min_pos;
    min_pos = find_min_position(*head_a);
    move_min_to_top1(head_a, min_pos);
    pb(head_a, head_b);

    four_nbr(head_a, head_b);

    pa(head_a, head_b);
}

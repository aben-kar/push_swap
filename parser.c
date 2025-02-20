/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:02:17 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/18 17:13:59 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (1);
}

int	handle_spaced_argument(char *arg, t_Node **head)
{
	t_push_swap	v;

	v.split_args = ft_split(arg, ' ');
	if (!v.split_args)
		return (free_list(head), 1);
	v.k = 0;
	while (v.split_args[v.k])
	{
		v.num = ft_atoi(v.split_args[v.k]);
		if (v.num == 21474836499)
		{
			free_list(head);
			return (ft_free(v.split_args), 1);
		}
		if (repetition(head, v.num) == 1 || cree_node(head, v.num) == 1)
		{
			ft_free(v.split_args);
			free_list(head);
			return (write_error("Error"));
		}
		v.k++;
	}
	return (ft_free(v.split_args), 0);
}

int	handle_single_argument(char *arg, t_Node **head)
{
	long	num;

	num = ft_atoi(arg);
	if (num == 21474836499)
	{
		free_list(head);
		return (1);
	}
	if (repetition(head, num) == 1 || cree_node(head, num) == 1)
	{
		free_list(head);
		return (write_error("Error"));
	}
	return (0);
}

int	validate_argument(char *arg)
{
	if (!arg || is_only_spaces(arg) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

t_Node	*parse_arguments(int ac, char **av)
{
	int		i;
	t_Node	*head;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		if (validate_argument(av[i]))
			return (free_list(&head), NULL);
		if (ft_strchr(av[i], ' '))
		{
			if (only_tab(av[i]) == 0)
			{
				write (2, "Error\n", 6);
				free_list(&head);
				return (NULL);
			}
			if (handle_spaced_argument(av[i], &head) == 1)
				return (NULL);
		}
		else if (handle_single_argument(av[i], &head) == 1)
			return (NULL);
		i++;
	}
	return (head);
}

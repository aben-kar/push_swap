/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:35:04 by acben-ka          #+#    #+#             */
/*   Updated: 2025/02/24 22:29:06 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *s)
{
	t_push_swap	v;

	v.i = 0;
	v.rs = 0;
	v.sign = 1;
	while ((s[v.i] >= '\t' && s[v.i] <= '\r') || s[v.i] == ' ')
		v.i++;
	if (s[v.i] == '-' || s[v.i] == '+')
	{
		if (s[v.i] == '-')
			v.sign = -1;
		v.i++;
		if (!ft_isdigit(s[v.i]))
			return (print_error("Error"));
	}
	while (s[v.i] >= '0' && s[v.i] <= '9')
	{
		v.rs = v.rs * 10 + (s[v.i] - '0');
		if ((v.rs * v.sign) > INT_MAX || (v.rs * v.sign) < INT_MIN)
			return (print_error("Error"));
		v.i++;
	}
	if (s[v.i] != '\0')
		return (print_error("Error"));
	return (v.rs * v.sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	if (size != 0 && (count > SIZE_MAX / size))
		return (NULL);
	s = (unsigned char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

long	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (21474836499);
}

int	ft_isdigit(int c)
{
	while (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	only_tab(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i]) == '\t')
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:18:22 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/21 11:21:01 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = (res * 10) + (str[i] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

t_node	*ft_new_node(char **av, int i)
{
	t_node	*new_node;

	new_node = malloc (sizeof (t_node));
	if (!new_node)
		return (NULL);
	new_node->value = ft_atoi(av[i]);
	new_node->index = i;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	ft_fill_nodes(t_stacks *stacks, int ac, char **av)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	i = 1;
	stacks->head_a = ft_new_node (av, i);
	tmp = stacks->head_a;
	i++;
	while (i < ac)
	{
		if (!ft_is_valid(av[i]))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		node = ft_new_node(av, i);
		if (!node)
			return (-1);
		node->prev = tmp;
		tmp->next = node;
		tmp = node;
		i++;
	}
	stacks->last_a = tmp;
	return (i);
}

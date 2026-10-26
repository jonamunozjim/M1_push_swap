/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:18:22 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/26 11:47:25 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_remove_flags(char **str, int ac)
{
	int	i;
	
	i = 1;
	while (i < ac)
	{
		if (!ft_strncmp (str[i], "--simple", 8) ||
			!ft_strncmp (str[i], "--medium", 8)||
			!ft_strncmp (str[i], "--complex", 9) ||
			!ft_strncmp (str[i], "--adaptive", 10) ||
			!ft_strncmp (str[i], "--bench", 7))
				i++;
		else
			return (i);
	}
	return (i);
}
	


int	ft_is_valid(char *str)
{
	int		i;
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	i = 0;
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

	i = ft_remove_flags(av, ac);
	stacks->head_a = ft_new_node (av, i);
	tmp = stacks->head_a;
	i++;
	while (i < ac)
	{
		if (!ft_is_valid(av[i]))
		{
			write(2, "Error_nodes\n", 12); //modify to Error
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:18:22 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/20 09:57:30 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_fill_nodes(t_stacks *stacks, int ac, char **av)
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
		node = ft_new_node(av, i);
		node->prev = tmp;
		prev->next = node;
		tmp = node;
		i++;
	}
	stacks->last_a = tmp;
}

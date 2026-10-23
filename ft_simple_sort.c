/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:35:25 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/23 11:25:22 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_min_node(t_stacks *stacks)
{
	t_node	*tmp_node;
	t_node	*min_node;
	
	if (!stacks->head_a)
		return (NULL);
	min_node = stacks->head_a;
	tmp_node = stacks->head_a->next;
	while (tmp_node)
	{
		if (tmp_node->value < min_node->value)
			min_node = tmp_node;
		tmp_node = tmp_node->next;
	}
	return (min_node);
}
int	ft_simple_sort(t_stacks *stacks)
{
	t_node	*min_node;
	int		count;

	count = 0;
	min_node = ft_min_node (stacks);
	while (stacks->head_a)
	{
		while (stacks->head_a->value != min_node->value)
		{
			ft_rotate_a(stacks, 1);
			count++;
		}
		ft_push_b (stacks);
		count++;
		if (stacks->head_a)
			min_node = ft_min_node (stacks);
	}
	while (stacks->head_b)
	{
		ft_push_a (stacks);
		count++;
	}
	return (count);
}

/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:46:28 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/22 09:53:32 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_sort_three(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stacks->head_a)
		return (0);
	first = stacks->head_a;
	second = stacks->head_a->next;
	third = stacks->head_a->next->next;
	
	if (first->value > second->value && first->value > third->value)
	{
		ft_rotate_a (stacks, 1);
		if (stacks->head_a->value > stacks->head_a->next->value)
			return (ft_swap_a (stacks, 1), 2);
		return (1);
	}
	if (first->value > second->value)
		return (ft_swap_a (stacks, 1), 1);
	if (second->value > first->value)
		ft_reverse_rotate_a (stacks, 1);
	if (stacks->head_a->value > stacks->head_a->next->value)
		return (ft_swap_a (stacks, 1), 2);
	else
		return (1);
}

int	ft_sort_five(t_stacks *stacks)
{
	
}


int	ft_sort_small(int nodes, t_stacks *stacks)
{
	if (nodes == 2)
		return (ft_swap_a, 1);
	else if (nodes == 3)
		return (ft_sort_three (stacks));
	else
		return  (ft_sort_five(stacks));
}

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
	int	first;
	int	second;
	int	third;

	if (!stacks->head_a)
		return (0);
	first = stacks->head_a->value;
	second = stacks->head_a->next->value;
	third = stacks->head_a->next->next->value;
	if (second > first && second > third)
	{
		ft_reverse_rotate_a (stacks, 1);
		if (first > second)
			return (ft_swap_a (stacks, 1), 2);
		return (1);
	}
	if (first > second & first > third)
		ft_rotate_a (stacks, 1);
	if (first < second)
		return (1);
	else
		return (ft_swap_a (stacks, 1), 2);
	return (0);
}

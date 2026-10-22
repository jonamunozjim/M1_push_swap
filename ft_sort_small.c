/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:11:56 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/22 14:37:50 by jmunoz-j         ###   ########.fr       */
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

int	ft_best_push_min(t_stacks *stacks, int op)
{
	int	count;
	
	count = 0;
	if (op >= 0)
	while (stacks->head_a->prev)
	{
		ft_rotate_a (stacks, 1);
		count++;
	}
	return (count);
}

int	ft_check_best_r(t_stacks *stacks)
{
	int	i;
	int	j;
	t_node	*tmp;

	i = 0;
	j = 1;
	tmp = ft_min_node (stacks);
	while (tmp)
	{
		if(tmp->next)
			i++;
		tmp = tmp->next;
	}
	tmp = ft_min_node (stacks);
	while (tmp)
	{
		if(tmp->prev)
			j++;
		tmp = tmp->prev;
	}
	if (i <= j)
		return (-i);
	return (j);
}

int ft_push_b_min(t_stacks *stacks)
{
	int	op;
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	op = ft_check_best_r (stacks);
	if (op >= 0)
	{
		while (i < op)
		{
			ft_reverse_rotate_a (stacks, 1);
			count++;
		}
	}
	else
		while (i < op)
		{
			ft_rotate_a (stacks, 1);
			count++;
		}
	ft_push_b (stacks);
	count++;
	return (count);
}

int	ft_sort_five(t_stacks *stacks, int nodes)
{
	int		count;
	
	count = ft_push_b_min (stacks);
	if (nodes == 5)
		count = count + ft_push_b_min (stacks);
	count = count + ft_sort_three (stacks);
	ft_push_a (stacks);
	count++;
	if (nodes == 5)
	{
		ft_push_a (stacks);
		count++;
	}
	return (count);
}

int	ft_sort_small(t_stacks *stacks, int nodes)
{
	if (nodes == 2)
		return (ft_swap_a (stacks, 1), 1);
	else if (nodes == 3)
		return (ft_sort_three (stacks));
	else
		return (ft_sort_five(stacks, nodes));
}

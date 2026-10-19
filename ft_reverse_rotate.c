/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:13:21 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/19 12:53:46 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (!stacks->head_a || !stacks->head_a->next)
		return ;
	tmp = stacks->last_a;
	stacks->last_a = tmp->prev;
	stacks->last_a->next = NULL;
	tmp->prev = NULL;
	stacks->head_a->prev = tmp;
	tmp->next = stacks->head_a;
	stacks->head_a = tmp;
	write(1, " rra", 4);
}

void	ft_reverse_rotate_b(t_stacks *stacks)
{
	t_node	*tmp;

	if (!stacks->head_b || !stacks->head_b->next)
		return ;
	tmp = stacks->last_b;
	stacks->last_b = tmp->prev;
	stacks->last_b->next = NULL;
	tmp->prev = NULL;
	stacks->head_b->prev = tmp;
	tmp->next = stacks->head_b;
	stacks->head_b = tmp;
	write(1, " rrb", 4);
}

void	ft_reverse_rotate_a_b(t_stacks *stacks)
{
	ft_reverse_rotate_a(stacks);
	ft_reverse_rotate_b(stacks);
}

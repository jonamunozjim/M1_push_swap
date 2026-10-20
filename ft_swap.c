/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:54:56 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/20 13:49:52 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *stacks, int write_flag)
{
	t_node	*tmp;

	if (!stacks->head_a || !stacks->head_a->next)
		return ;
	tmp = stacks->head_a->next;
	stacks->head_a->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = stacks->head_a;
	stacks->head_a->prev = tmp;
	tmp->prev = NULL;
	tmp->next = stacks->head_a;
	stacks->head_a = tmp;
	if (!stacks->head_a->next->next)
		stacks->last_a = stacks->head_a->next;
	if (write_flag)
		write (1, " sa", 3);
}

void	ft_swap_b(t_stacks *stacks, int write_flag)
{
	t_node	*tmp;

	if (!stacks->head_b || !stacks->head_b->next)
		return ;
	tmp = stacks->head_b->next;
	stacks->head_b->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = stacks->head_b;
	stacks->head_b->prev = tmp;
	tmp->prev = NULL;
	tmp->next = stacks->head_b;
	stacks->head_b = tmp;
	if (!stacks->head_b->next->next)
		stacks->last_b = stacks->head_b->next;
	if (write_flag)
		write (1, " sb", 3);
}

void	ft_swap_a_b(t_stacks *stacks, int write_flag)
{
	ft_swap_a (stacks, 0);
	ft_swap_b (stacks, 0);
	write (1, " ss", 3);
}

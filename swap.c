/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:54:56 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/19 12:09:40 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *stacks)
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
	write (1, " sa", 3);
}
void	ft_swap_b(t_stacks *stacks)
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
		stacks->last_a = stacks->head_b->next;
	write (1, " sb", 3);
}

void	ft_swap_ss(t_stacks *stacks)
{
	ft_swap_sa (stacks);
	ft_swa_sb (stacks);
	write (1, " (equiv. to ss)", 15);
}

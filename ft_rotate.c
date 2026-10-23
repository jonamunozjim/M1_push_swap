/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:32:58 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 12:12:08 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stacks *stacks, int write_flag)
{
	t_node	*tmp;

	if (!stacks->head_a || !stacks->head_a->next)
		return ;
	tmp = stacks->head_a;
	stacks->head_a = tmp->next;
	stacks->head_a->prev = NULL;
	tmp->next = NULL;
	stacks->last_a->next = tmp;
	tmp->prev = stacks->last_a;
	stacks->last_a = tmp;
	if (write_flag)
		ft_track_op(stacks, "ra");
}

void	ft_rotate_b(t_stacks *stacks, int write_flag)
{
	t_node	*tmp;

	if (!stacks->head_b || !stacks->head_b->next)
		return ;
	tmp = stacks->head_b;
	stacks->head_b = tmp->next;
	stacks->head_b->prev = NULL;
	tmp->next = NULL;
	stacks->last_b->next = tmp;
	tmp->prev = stacks->last_b;
	stacks->last_b = tmp;
	if (write_flag)
		ft_track_op(stacks, "rb");
}

void	ft_rotate_a_b(t_stacks *stacks)
{
	ft_rotate_a(stacks, 0);
	ft_rotate_b(stacks, 0);
	ft_track_op(stacks, "rr");
}

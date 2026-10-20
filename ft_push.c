/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:41:17 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/19 12:37:34 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (!stacks->head_b)
		return ;
	tmp = stacks->head_b;
	if (!stacks->head_b->prev && !stacks->head_b->next)
	{
		stacks->head_b = NULL;
		stacks->last_b = NULL;
	}
	else
	{
		stacks->head_b = stacks->head_b->next;
		stacks->head_b->prev = NULL;
	}
	tmp->next = stacks->head_a;
	if (!stacks->head_a)
		stacks->last_a = tmp;
	else
		stacks->head_a->prev = tmp;
	stacks->head_a = tmp;
	write (1, " pa", 3);
}

void	ft_push_b(t_stacks *stacks)
{
	t_node	*tmp;

	if (!stacks->head_a)
		return ;
	tmp = stacks->head_a;
	if (!stacks->head_a->prev && !stacks->head_a->next)
	{
		stacks->head_a = NULL;
		stacks->last_a = NULL;
	}
	else
	{
		stacks->head_a = stacks->head_a->next;
		stacks->head_a->prev = NULL;
	}
	tmp->next = stacks->head_b;
	if (!stacks->head_b)
		stacks->last_b = tmp;
	else
		stacks->head_b->prev = tmp;
	stacks->head_b = tmp;
	write (1, " pb", 3);
}
/*
void	ft_push_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (!stacks->head_b)
		return ;
	tmp = stacks->head_b;
	if (!stacks->head_b->prev && !stacks->head_b->next)
	{
		stacks->head_b = NULL;
		stacks->last_b = NULL;
	}
	else
	{
		stacks->head_b = stacks->head_b->next;
		stacks->head_b->prev = NULL;
		if (!stacks->head_b->next)
			stacks->last_b = stacks->head_b;
	}
	if(!stacks->head_a)
	{
		tmp->next = NULL;
		stacks->head_a = tmp;
		stacks->last_a = stacks->head_a;
	}
	else
	{
		tmp->next = stacks->head_a;
		stacks->head_a->prev = tmp;
		stacks->head_a = tmp;
	}
	write (1, " pa",3);
}*/
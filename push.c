/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:41:17 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/16 15:42:18 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (stacks->head_b == NULL)
		return ;
	if (!stacks -> head_a)
	{
		tmp = stacks->head_b;
		tmp -> next = NULL;
		stacks->head_b = tmp -> next;
		if (stacks->head_b)
			(stacks->head_b) -> prev = NULL;
		stacks -> head_a = tmp;
		stacks -> last_a = tmp;
	}
	else
	{
		tmp = stacks->head_b;
		stacks->head_b = tmp -> next;
		if (stacks->head_b)
			(stacks->head_b)-> prev = NULL;
		(stacks -> head_a) -> prev = tmp;
		tmp -> next = stacks -> head_a;
		stacks -> head_a = tmp;
	}
}

void	ft_push_b(t_stacks *stacks)
{
	t_node	*tmp;

	if (head_a == NULL)
		return ;
	if (!*head_b)
	{
		tmp = *head_a;
		*head_a = tmp -> next;
		(*head_a) -> prev = NULL;
		*head_b = tmp;
		*last_b = tmp;
	}
	else
	{
		tmp = *head_a;
		*head_a = tmp -> next;
		(*head_a)-> prev = NULL;
		(*head_b) -> prev = tmp;
		tmp -> next = *head_b;
		*head_b = tmp;
	}
//	free (tmp);
}
/*
void	ft_push_b(t_stacks *stacks)
{
	if (head_a == NULL)
		return ;
	if (!*head_b)
	{
		*head_b = *head_a;
		*last_b = *head_a;
	}
	else
	{
		(*head_b)-> prev = *head_a;
		(*head_a) -> next = *head_b;
		*head_b = *head_a;
	}
}*/

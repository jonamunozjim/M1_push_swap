/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:32:58 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/19 12:35:43 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate_a(t_stacks *stacks)
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
    write(1, " ra", 3);
}

void    ft_rotate_b(t_stacks *stacks)
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
    write(1, " rb", 3)
}

void    ft_rotate_a_b(t_stacks *stacks)
{
    ft_rotate_a(stacks);
    ft_rotate_b(stacks);
}


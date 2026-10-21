/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:46:28 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/21 13:18:59 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int ft_sort_three(t_stacks *stacks)
{
    t_node  *first;
    t_node  *second;
    t_node  *third;
    int     count;

    count = 0;
    if (first->value > second->value && first->value > third->value)
    {
        ft_rotate_a (stacks, 1);
        ft_swap_a (stacks, 1);
        count++;
    }
    else if ()
}

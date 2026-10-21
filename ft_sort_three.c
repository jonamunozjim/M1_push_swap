/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:46:28 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/21 14:49:18 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int ft_sort_three(t_stacks *stacks)
{
    int	first;
    int second;
	int	third;
	int	count;

    count = 0;
    if (second > third)
	{
		ft_reverse_rotate_a (stacks, 1);
		count ++;
		if (first > second)
			return (ft_swap_a (stacks, 1), count++);
		return (count);
	}
	

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:49:12 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/21 10:06:07 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_disorder(t_stacks *stacks)
{
	int		mistakes;
	int		total_pairs;
	t_node	*nodo_i;
	t_node	*nodo_j;

	mistakes = 0;
	total_pairs = 0;
	nodo_i = stacks -> head_a;
	while (nodo_i != NULL)
	{
		nodo_j = nodo_i -> next;
		while (nodo_j != NULL)
		{
			total_pairs++;
			if (nodo_i -> value > nodo_j -> value)
				mistakes++;
			if (nodo_i -> value == nodo_j -> value)
				return (write (2, "Error\n", 6), -1);
			nodo_j = nodo_j -> next;
		}
		nodo_i = nodo_i -> next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / total_pairs);
}

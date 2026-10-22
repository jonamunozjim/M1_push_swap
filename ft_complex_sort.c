/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:32:41 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/22 09:49:45 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stack(t_stacks *stacks)
{
	t_node	*current;
	t_node	*compare;
	int		index_count;

	current = stacks->head_a;
	while (current != NULL)
	{
		index_count = 0;
		compare = stacks->head_a;
		while (compare != NULL)
		{
			if (current->value > compare->value)
				index_count++;
			compare = compare->next;
		}
		current->chunk_index = index_count;
		current = current->next;
	}
}

int get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int ft_complex_sort(t_stacks *stacks, int total_nodes)
{
	int	i;
	int	j;
	int	max_bits;
	int	count;

	count = 0;
	ft_index_stack(stacks);
	max_bits = get_max_bits(total_nodes - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < total_nodes)
		{
			if (((stacks->head_a->chunk_index >> i) & 1) == 0)
			{
				ft_push_b(stacks);
				count++;
			}
			else
			{
				ft_rotate_a(stacks, 1);
				count++;
			}
			j++;
		}
		while (stacks->head_b != NULL)
		{
			ft_push_a(stacks);
			count++;
		}
		i++;
	}
	return (count);
}
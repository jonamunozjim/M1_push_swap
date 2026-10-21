/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:09:04 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/21 13:25:47 by fejimene         ###   ########.fr       */
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

int	ft_sort_to_b(t_stacks *stacks, int total_nodes)
{
	int	i;
	int	range;
	int	count;

	count = 0;
	i = 0;
	if (total_nodes <= 100)
		range = 15;
	else
		range = 45;
	while (stacks->head_a != NULL)
	{
		if (stacks->head_a->chunk_index <= i)
		{
			ft_push_b(stacks);
			ft_rotate_b(stacks, 1);
			i++;
			count++;
		}
		else if (stacks->head_a->chunk_index <= i + range)
		{
			ft_push_b(stacks);
			i++;
		}
		else
			ft_rotate_a(stacks, 1);
		count++;
	}
	return (count);
}

int	get_max_pos(t_node *head)
{
	int		pos;
	int		max_pos;
	int		max_index;
	t_node	*tmp;

	pos = 0;
	max_pos = 0;
	max_index = -1;
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->chunk_index > max_index)
		{
			max_index = tmp->chunk_index;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

int	ft_bring_to_top(t_stacks *stacks, int max_pos, int size_b)
{
	int	count;

	count = 0;
	if (max_pos <= size_b / 2)
	{
		while (max_pos > 0)
		{
			ft_rotate_b(stacks, 1);
			max_pos--;
			count++;
		}
	}
	else
	{
		while (max_pos < size_b)
		{
			ft_reverse_rotate_b(stacks, 1);
			max_pos++;
			count++;
		}
	}
	return (count);
}

int	ft_medium_sort(t_stacks *stacks, int total_nodes)
{
	int	max_pos;
	int	size_b;
	int	count;

	ft_index_stack(stacks);
	count = ft_sort_to_b(stacks, total_nodes);
	size_b = total_nodes;
	while (size_b > 0)
	{
		max_pos = get_max_pos(stacks->head_b);
		count = count + ft_bring_to_top(stacks, max_pos, size_b);
		ft_push_a(stacks);
		size_b--;
	}
	return (count);
}

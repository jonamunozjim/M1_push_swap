/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:15:01 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/27 21:57:14 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"
#include "push_swap.h"
#include "checker.h"

int	ft_check_op_push_swap(t_stacks *stacks, char *op)
{
	if (!ft_strncmp (op, "sa\n", 3))
		ft_swap_a(stacks, 0);
	else if (!ft_strncmp (op, "sb\n", 3))
		ft_swap_b(stacks, 0);
	else if (!ft_strncmp (op, "ss\n", 3))
		ft_swap_a_b (stacks, 0);
	else if (!ft_strncmp (op, "pa\n", 3))
		ft_push_a(stacks, 0);
	else if (!ft_strncmp (op, "pb\n", 3))
		ft_push_b (stacks, 0);
	else
		return (-1);
	return (0);
}

int	ft_check_rot_rev_rot(t_stacks *stacks, char *op)
{
	if (!ft_strncmp (op, "ra\n", 3))
		ft_rotate_a(stacks, 0);
	else if (!ft_strncmp (op, "rb\n", 3))
		ft_rotate_b(stacks, 0);
	else if (!ft_strncmp (op, "rr\n", 3))
		ft_rotate_a_b(stacks, 0);
	else if (!ft_strncmp (op, "rra\n", 4))
		ft_reverse_rotate_a(stacks, 0);
	else if (!ft_strncmp (op, "rrb\n", 4))
		ft_reverse_rotate_b(stacks, 0);
	else if (!ft_strncmp (op, "rrr\n", 4))
		ft_reverse_rotate_a_b (stacks, 0);
	else
		return (-1);
	return (0);
}

int	run_operations(t_stacks *stacks)
{
	char	*op;

	op = get_next_line (0);
	while (op)
	{
		if (ft_check_op_push_swap (stacks, op) < 0
			&& ft_check_rot_rev_rot (stacks, op) < 0)
			return (free(op), write (2, "Error\n", 6), -1);
		free (op);
		op = get_next_line (0);
	}
	free (op);
	return (0);
}

void	ft_free_all(t_stacks *stacks, int *arg)
{
	ft_dlstclear (&(stacks->head_a));
	ft_dlstclear (&(stacks->head_b));
	free (stacks);
	free (arg);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	float		disorder_i;
	char		**input;
	int			*arg;

	if (ac == 1)
		return (0);
	arg = ft_calloc (1, sizeof(int));
	stacks = ft_init_stacks ();
	input = ft_process_arg_checker (ac, av, arg);
	if (ft_fill_nodes(stacks, ac, input) <= 0)
		return (ft_free_all (stacks, arg), 0);
	if (ft_disorder (stacks) < 0 || run_operations (stacks) < 0)
		return (ft_free_all (stacks, arg), 0);
	disorder_i = ft_disorder (stacks);
	if (disorder_i == 0 && !stacks->head_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_free_all (stacks, arg);
	return (0);
}

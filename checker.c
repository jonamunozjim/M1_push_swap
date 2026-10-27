/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:15:01 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/27 16:30:17 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"
#include "push_swap.h"
#include "checker.h"

void	ft_check_op_push_swap(t_stacks *stacks, char *op)
{
	if (!ft_strncmp (op, "sa", 2))
		ft_swap_a(stacks, 0);
	else if (!ft_strncmp (op, "sb", 2))
		ft_swap_b(stacks, 0);
	else if (!ft_strncmp (op, "ss", 2))
		ft_swap_a_b (stacks);
	else if (!ft_strncmp (op, "pa", 2))
		ft_push_a(stacks);
	else if (!ft_strncmp (op, "pb", 2))
		ft_push_b(stacks);
}
void	ft_check_rot_rev_rot(t_stacks *stacks, char *op)
{
	if (!ft_strncmp (op, "ra", 2))
		ft_rotate_a(stacks, 0);
	else if (!ft_strncmp (op, "rb", 2))
		ft_rotate_b(stacks, 0);
	else if (!ft_strncmp (op, "rr", 2))
		ft_rotate_a_b(stacks);
	else if (!ft_strncmp (op, "rra", 3))
		ft_reverse_rotate_a(stacks, 0);
	else if (!ft_strncmp (op, "rrb", 3))
		ft_reverse_rotate_b(stacks, 0);
	else if (!ft_strncmp (op, "rrr", 3))
		ft_reverse_rotate_a_b (stacks);
}
void	run_operations(t_stacks *stacks)
{
	char	*op;

	op = get_next_line (0);
	//printf("%s", op);
	while (op)
	{
		ft_check_op_push_swap (stacks, op);
		ft_check_rot_rev_rot (stacks, op);
		op = get_next_line (0);
		//printf("%s", op);
	}
	free (op);
}
/*void	ft_write_result(t_stacks *stacks, float disorder_i)
{
	if (disorder_i == 0 && !stacks->head_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}*/

int	ft_is_sorted(t_stacks *stacks)
{
	t_node *tmp;

	tmp = stacks->head_a;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
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
	ft_fill_nodes(stacks, ac, av);
	disorder_i = ft_disorder (stacks);
	run_operations (stacks);
	if (ft_is_sorted (stacks) && !stacks->head_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_dlstclear (&(stacks->head_a));
	ft_dlstclear (&(stacks->head_b));
	free (stacks);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:15:01 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/27 09:45:35 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*read_operations(void)
{
	int	fd;

	fd = open (file,O_RDONLY);
	get_next_line(fd);
}

void	ft_check_op_push_swap(t_stacks *stacks)
{
	if (sa)
		ft_swap_a(stacks, 0);
	else if (sb)
		ft_swap_b(stacks, 0);
	else if (ss)
		ft_swap_a_b(stacks, 0);
	else if (pa)
		ft_push_a(stacks);
	else if (pb)
		ft_push_b(stacks);
}
void	ft_check_rot_rev_rot(t_stacks *stacks)
{
	if (ra)
		ft_rotate_a(stacks, 0);
	else if (rb)
		ft_rotate_b(stacks, 0);
	else if (rr)
		ft_rotate_a_b(stacks, 0);
	else if (rra)
		ft_reverse_rotate_a(stacks, 0);
	else if (rrb)
		ft_reverse_rotate_b(stacks, 0);
	else if (rrr)
		ft_reverse_rotate_a_b(stacks, 0);
}
int	exec_operation(t_stacks *stacks, int fd, char **op_list)
{
	
	while (fd > 0)
	{
		ft_check_op_push_swap (stacks, op_list[i]);
		ft_check_rot_rev_rot (stacks, op_list[i]);
	}
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	float		disorder_i;
	char		**input;
	int			*flags;

	//check errors antes de empezar?
	

}
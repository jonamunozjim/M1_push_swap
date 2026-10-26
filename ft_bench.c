/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:47:20 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/26 09:47:20 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"
#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	ft_track_op(t_stacks *stacks, char *op, int len)
{
	write(1, op, len);
	write(1, "\n", 1);
	stacks->bench.total++;
	if (op[0] == 's' && op[1] == 'a')
		stacks->bench.sa++;
	else if (op[0] == 's' && op[1] == 'b')
		stacks->bench.sb++;
	else if (op[0] == 's' && op[1] == 's')
		stacks->bench.ss++;
	else if (op[0] == 'p' && op[1] == 'a')
		stacks->bench.pa++;
	else if (op[0] == 'p' && op[1] == 'b')
		stacks->bench.pb++;
	else if (op[0] == 'r' && op[1] == 'a' && !op[2])
		stacks->bench.ra++;
	else if (op[0] == 'r' && op[1] == 'b' && !op[2])
		stacks->bench.rb++;
	else if (op[0] == 'r' && op[1] == 'r' && !op[2])
		stacks->bench.rr++;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a')
		stacks->bench.rra++;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b')
		stacks->bench.rrb++;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r')
		stacks->bench.rrr++;
}

static void	ft_print_padded(int n, int fd)
{
	if (n < 10)
		ft_putstr_fd("   ", fd);
	else if (n < 100)
		ft_putstr_fd("  ", fd);
	else if (n < 1000)
		ft_putstr_fd(" ", fd);
	ft_putnbr_fd(n, fd);
}

static void	print_bench_ops(t_bench *bench)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_print_padded(bench->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_print_padded(bench->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_print_padded(bench->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_print_padded(bench->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_print_padded(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_print_padded(bench->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_print_padded(bench->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_print_padded(bench->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_print_padded(bench->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_print_padded(bench->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_print_padded(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_bench *bench)
{
	int	integer;
	int	decimal;

	integer = (int)(bench->disorder * 100);
	decimal = (int)((bench->disorder * 100.0 - integer) * 100);
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(integer, 2);
	ft_putstr_fd(".", 2);
	if (decimal < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n[bench] strategy:  ", 2);
	ft_putstr_fd(bench->strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2);
	print_bench_ops(bench);
}

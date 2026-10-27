/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:37:30 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/15 19:37:30 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"
#include "push_swap.h"

void	ft_adaptive(t_stacks *stacks, float disorder_i, int ac)
{
	if (disorder_i < 0.2)
	{
		stacks->bench.strategy = "Adaptative / O(n^2)";
		ft_simple_sort(stacks);
	}
	else if (disorder_i >= 0.2 && disorder_i < 0.5)
	{
		stacks->bench.strategy = "Adaptative / O(n√n)";
		ft_medium_sort(stacks, ac);
	}
	else
	{
		stacks->bench.strategy = "Adaptative / O(n log n)";
		ft_complex_sort(stacks, ac);
	}
}

void	ft_small(t_stacks *stacks, int *flags, float disorder_i, int ac)
{
	stacks->bench.strategy = "Adaptive / O(n^2)";
	if (flags[0] == 1)
		stacks->bench.strategy = "Simple / O(n^2)";
	else if (disorder_i < 0.2)
		stacks->bench.strategy = "Adaptative / O(n^2)";
	else if (disorder_i >= 0.2 && disorder_i < 0.5)
		stacks->bench.strategy = "Adaptative / O(n√n)";
	else
		stacks->bench.strategy = "Adaptative / O(n log n)";
	ft_sort_small(stacks, ac);
}

void	ft_strategy(t_stacks *stacks, float disorder_i, int ac, int *flags)
{
	if (flags[0] == 1)
	{
		stacks->bench.strategy = "Simple / O(n^2)";
		ft_simple_sort (stacks);
	}
	else if (flags[0] == 2)
	{
		stacks->bench.strategy = "Medium / O(n√n)";
		ft_medium_sort (stacks, ac);
	}
	else if (flags[0] == 3)
	{
		stacks->bench.strategy = "Complex / O(n log n)";
		ft_complex_sort (stacks, ac);
	}
	else if (ac <= 5)
		ft_small(stacks, flags, disorder_i, ac);
	else
		ft_adaptive (stacks, disorder_i, ac);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	float		disorder_i;
	char		**input;
	int			*flags;

	if (ac == 1)
		return (0);
	flags = set_flags(ac, av);
	if (!flags)
		return (write (2, "Error\n", 6), 0);
	input = ft_process_arg (ac, av, flags);
	if (flags[2] == 1)
		return (write (2, "Error\n", 6), free(flags), ft_free_input(input), 0);
	stacks = ft_init_stacks ();
	ac = ft_fill_nodes(stacks, flags[2], input);
	if (ac < 0)
		return (ft_free_stacks (stacks, flags, av, input), 0);
	disorder_i = ft_disorder (stacks);
	if (disorder_i <= 0)
		return (ft_free_stacks (stacks, flags, av, input), 0);
	stacks->bench.disorder = disorder_i;
	ft_strategy (stacks, disorder_i, ac, flags);
	if (flags[1] == 1)
		ft_bench(&(stacks->bench));
	return (ft_free_stacks (stacks, flags, av, input), 0);
}

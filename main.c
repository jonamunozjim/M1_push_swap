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

void	ft_free_stacks(t_stacks *stacks, int *flags)
{
	ft_dlstclear (&(stacks->head_a));
	ft_dlstclear (&(stacks->head_b));
	free (stacks);
	free (flags);
}

t_stacks	*ft_init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc (sizeof (t_stacks));
	if (!stacks)
		return (NULL);
	stacks->head_a = NULL;
	stacks ->head_b = NULL;
	return (stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	float		disorder_i;
	int			op_count;
	char		**input;
	int			*flags; //0, algoritm; 1 bench; 2 ac

	flags = set_flags(ac, av);
	if (!flags)
		return (write (2, "Error\n", 6), 0);
	printf("Algor: %i\nBench: %i\n", flags[0], flags[1]); //for testing only, delete
	input = ft_process_arg (ac, av, flags);
	/*if (flags[1])
		//lamar al bench*/
	op_count = 0;
	if (ac == 1)
		return (0);
	stacks = ft_init_stacks ();
	ac = ft_fill_nodes(stacks, flags[2], input);
	if (ac < 0)
		return (ft_free_stacks (stacks, flags), 0);
	disorder_i = ft_disorder (stacks);
	if (disorder_i == 0)
		return (ft_free_stacks (stacks, flags), 0);
	printf("%f\n", disorder_i);
	stacks->bench.disorder = disorder_i;
	printf("arg: %i\n", ac);
	if (flags[0] == 1)
	{
		stacks->bench.strategy = "Simple / O(n^2)";
		op_count = ft_simple_sort (stacks);
		printf("\n*simple*\n");
	}
	else if (flags[0] == 2)
	{
		stacks->bench.strategy = "Medium / O(n√n)";
		op_count = ft_medium_sort (stacks, ac);
		printf("\n*medium*\n");
	}
	else if (flags[0] == 3)
	{
		stacks->bench.strategy = "Complex / O(n log n)";
		op_count = ft_complex_sort (stacks, ac);
		printf("\n*complex*\n");
	}
	else if	(ac <= 5)
	{
		stacks->bench.strategy = "Simple / O(n^2)";
		op_count = ft_sort_small(stacks, ac);
		printf("\n*small*\n");
	}
	else
	{
		if (disorder_i < 0.2)
		{
			stacks->bench.strategy = "Adaptative / O(n^2)";
			op_count = ft_simple_sort(stacks);
		}
		else if (disorder_i >= 0.2 && disorder_i < 0.5)
		{
			stacks->bench.strategy = "Adaptative / O(n√n)";
			op_count = ft_medium_sort(stacks, ac);
		}
		else
		{
			stacks->bench.strategy = "Adaptative / O(n log n)";
			op_count = ft_complex_sort(stacks, ac);
		}
		printf("\n*adaptive*\n");
	}
	if (flags[1] == 1)
		ft_bench(&(stacks->bench));
	printf("----Movements: %i\n", op_count);
	return (ft_free_stacks (stacks, flags), 0);
}

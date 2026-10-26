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
	
	printf("%s", av)
	return (0);
	/*if (flags[1])
		//lamar al bench*/
	op_count = 0;
	if (ac == 1)
		return (0);
	stacks = ft_init_stacks ();
	if (ft_fill_nodes(stacks, ac, input) < 0)
		return (ft_free_stacks (stacks, flags), 0);
	disorder_i = ft_disorder (stacks);
	if (disorder_i < 0)
		return (ft_free_stacks (stacks, flags), 0);
	printf("%f\n", disorder_i);
	printf("arg: %i\n", (ac - 1));
	if (ac <= 6)
		op_count = ft_sort_small (stacks, (ac - 1));
	//op_count = ft_complex_sort (stacks, (ac - 1));
	printf("----Movements: %i\n", op_count);
	return (ft_free_stacks (stacks, flags), 0);
}

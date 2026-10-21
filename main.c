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

#include "libft.h"
#include "push_swap.h"

void	ft_free_stacks(t_stacks *stacks)
{
	ft_dlstclear (&(stacks->head_a));
	ft_dlstclear (&(stacks->head_b));
	free (stacks);
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

	op_count = 0;
	if (ac == 1)
		return (0);
	stacks = ft_init_stacks ();
	if (ft_fill_nodes(stacks, ac, av) < 0)
		return (ft_free_stacks (stacks), 0);
	disorder_i = ft_disorder (stacks);
	if (disorder_i < 0)
		return (ft_free_stacks (stacks), 0);
	printf("%f\n", disorder_i);
	op_count = ft_simple_sort (stacks);
	printf("----Movements: %i\n", op_count);
	return (ft_free_stacks (stacks), 0);
}

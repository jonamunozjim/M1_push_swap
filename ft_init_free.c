/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_init_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:46:22 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/26 14:38:34 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stacks(t_stacks *stacks, int *flags, char **av, char **input)
{
	ft_dlstclear (&(stacks->head_a));
	ft_dlstclear (&(stacks->head_b));
	free (stacks);
	free (flags);
	if (input != av)
		ft_free_input(input);
}

t_stacks	*ft_init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc (sizeof (t_stacks));
	if (!stacks)
		return (NULL);
	stacks->head_a = NULL;
	stacks ->head_b = NULL;
	init_bench(&(stacks->bench));
	return (stacks);
}

void	ft_free_input(char **input)
{
	int	i;

	if (!input)
		return ;
	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

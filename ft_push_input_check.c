/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_input_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:20:41 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/23 11:25:22 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"
#include "push_swap.h"

int	ft_check_flag_error (int flag_current, int flag_new)
{
	if (flag_current == 0)
		return (flag_new);
	else
		return (-1);
}

int	*set_flags(int ac, char **av)
{
	int		i;
	int		*flags;

	i = -1;
	flags = calloc (2, sizeof(int));
	if (!flags)
		return (NULL);
	while (av[i])
	{
		if (av[i] == "--simple")
			flags[0] = ft_check_double_flag (flags[0], 1)
		if (av[i] == "--medium")
			flags[0] = ft_check_double_flag (flags[0], 2)
		if (av[i] == "--complex")
			flags[0] = ft_check_double_flag (flags[0], 3)
		if (av[i] == "--adaptive")
			flags[0] = ft_check_double_flag (flags[0], 4)
		if (av[1] == "--bench")
			flags[1] = ft_check_double_flag (flags[1], 1)
		if (flags[0] < 0 || flags[1] < 0)
			return (NULL);
		i++;
	}
	return (set_flags);
}

int	ft_check_if_split (int ac, char av)
{
	int	i;

	i = 1;

	while (i < av)
	{
		if ft_strchr(av[i], ' ');
	} 
}
char	*input(int ac, char **av, int *flags)
{
	char	*alg_mode;

	if (set_flags < 0)
		return (NULL)



		

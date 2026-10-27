/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_input_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:20:41 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/27 16:30:18 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"
#include "push_swap.h"
#include "checker.h"

unsigned int	word_count_checker(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}

char	*ft_join_checker_args(int ac, char **av)
{
	char	*full_str;
	char	*tmp1;
	char	*tmp2;
	int		i;

	full_str = ft_strjoin("x ", av[1]);
	i = 2;
	while (i < ac)
	{
		tmp1 = ft_strjoin(full_str, " ");
		free(full_str);
		tmp2 = ft_strjoin(tmp1, av[i]);
		free(tmp1);
		full_str = tmp2;
		i++;
	}
	return (full_str);
}

char	**ft_process_arg_checker(int ac, char **av, int *arg)
{
	int		i;
	char	*full_str;
	char	**output;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			full_str = ft_join_checker_args(ac, av);
			*arg = word_count_checker(full_str, ' ');
			output = ft_split(full_str, ' ');
			free(full_str);
			return (output);
		}
		i++;
	}
	*arg = ac;
	return (av);
}

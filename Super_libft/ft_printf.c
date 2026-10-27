/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 12:55:43 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:17:30 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		check;

	va_start(args, str);
	i = 0;
	check = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			check = check + ft_conver(str[i + 1], args);
			i++;
		}
		else
			check = check + ft_putchar_print(str[i]);
		if (check == -1)
			return (va_end(args), -1);
		i++;
	}
	va_end(args);
	return (check);
}

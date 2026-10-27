/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:24:17 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:17:30 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

int	ft_conver(char const str, va_list args)
{
	if (str == 'c')
		return (ft_putchar_print(va_arg(args, int)));
	else if (str == 's')
		return (ft_putstr_print(va_arg(args, char *)));
	else if (str == 'p')
		return (ft_putptr_print(va_arg(args, void *)));
	else if (str == 'd')
		return (ft_putnbr_print(va_arg(args, int)));
	else if (str == 'i')
		return (ft_putnbr_print(va_arg(args, int)));
	else if (str == 'u')
		return (ft_putunbr_print(va_arg(args, unsigned int)));
	else if (str == 'x')
		return (ft_puthex_print(va_arg(args, unsigned int), 'x'));
	else if (str == 'X')
		return (ft_puthex_print(va_arg(args, unsigned int), 'X'));
	else if (str == '%')
		return (ft_putchar_print('%'));
	return (0);
}

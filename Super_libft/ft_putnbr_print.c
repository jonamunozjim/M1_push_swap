/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 11:14:21 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:17:30 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

int	ft_putnbr_print(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count = count + ft_putchar_print('-');
		n = n * -1;
	}
	if (n >= 0 && n < 10)
		count = count + ft_putchar_print((n + '0'));
	else
	{
		count = count + ft_putnbr_print((n / 10));
		count = count + ft_putnbr_print((n % 10));
	}
	return (count);
}

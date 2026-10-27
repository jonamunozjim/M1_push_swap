/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 11:15:11 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:17:30 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

int	ft_putunbr_print(unsigned int n)
{
	int	num;

	num = 0;
	if (n > 9)
	{
		num = num + ft_putunbr_print(n / 10);
	}
	num = num + ft_putchar_print(n % 10 + '0');
	return (num);
}

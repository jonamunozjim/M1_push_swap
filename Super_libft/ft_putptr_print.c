/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 11:14:42 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:17:30 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

int	ft_putptr_print(void *ptr)
{
	int				i;
	unsigned long	nb;

	i = 0;
	nb = (unsigned long)ptr;
	if (!nb)
		return (write(1, "(nil)", 5));
	i = i + ft_putstr_print("0x");
	i = i + ft_puthex_print(nb, 'x');
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:55:24 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Sets a specific amount of bytes in memory to zero.
It calls ft_memset and passes 0 as the value.
*/

void	ft_bzero(void *ptr, size_t n)
{
	ft_memset(ptr, 0, n);
}
/*
int main(void) {
    char str[] = "12345";
    ft_bzero(str, 2);
    printf(str[2]);
    return (0);
}
*/
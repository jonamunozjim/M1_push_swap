/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:34:31 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Fills a block of memory with a specific value.
Loops x times, setting each byte to the value x.
Returns a pointer to the memory area.
*/

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char *)ptr)[i] = (unsigned char) x;
		i++;
	}
	return (ptr);
}
/*
int main(void) {
    char str[15] = "Hola Mundo";
    ft_memset(str, '*', 4);
    printf(str);
    return (0);
}
*/
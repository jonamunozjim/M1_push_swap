/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 08:55:36 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Copies x bytes from the source memory to the destination memory.
Goes through the memory area and copies byte by byte.
Returns the destination pointer.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		(((char *)dest)[i]) = ((const char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main(void) {
    char dest[20];
    ft_memcpy(dest, "Memoria copiada", 16);
    printf(dest);
    return (0);
}
*/
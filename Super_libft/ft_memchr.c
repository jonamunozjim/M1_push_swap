/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:00:58 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Searches for a specific character in a memory area.
Goes through x bytes looking for the character.
Returns a pointer to the matching byte.
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *)str)[i]);
		i++;
	}
	return (0);
}
/*
int main(void) {
    char str[] = "Encuentra la X aqui";
    char *res = (char *)ft_memchr(str, 'X', 15);
    printf(res);
    return (0);
}
*/
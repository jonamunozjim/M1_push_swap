/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:15:08 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Searches for a small string inside a big string.
Only searches up to x characters.
Returns a pointer to the start of the found string.
*/

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (lil[h] == '\0')
		return ((char *)big);
	while (big[h])
	{
		n = 0;
		while (big[h + n] == lil[n] && (h + n) < len)
		{
			if (big[h + n] == '\0' && lil[n] == '\0')
				return ((char *)big + h);
			n++;
		}
		if (lil[n] == '\0')
			return ((char *)big + h);
		h++;
	}
	return (0);
}
/*
int main(void) {
    char *big = "Buscando la aguja en el pajar";
    printf(ft_strnstr(big, "aguja", 20));
    return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:08:52 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Compares up to x characters of two strings.
Goes through both strings, if it finds a difference, it returns the difference.
If they are exactly the same, it returns 0.
*/

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
		{
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		}
		else if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
/*
int main(void) {
    printf(ft_strncmp("Hola", "Holo", 3));
    printf(ft_strncmp("Hola", "Holo", 4));
    return (0);
}
*/
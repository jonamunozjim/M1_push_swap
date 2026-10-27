/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 09:58:08 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Converts an uppercase letter to a lowercase letter.
If the character is between 'A' and 'Z', it adds 32 to its ASCII value.
*/

int	ft_tolower(int n)
{
	if (n >= 65 && n <= 90)
	{
		n = n + 32;
	}
	return (n);
}
/*
int main(void) {
    printf(ft_tolower('M'));
    return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:09:35 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Checks if a character is printable.
Returns 1 if the value is between 32 and 126, and 0 if not.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int main(void) {
    printf(ft_isprint(' '));
    printf(ft_isprint(10));
    return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:17:18 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Searches for the first time a character appears in a string.
Goes through the string until it finds the character. 
Returns a pointer to the character, 
then a control if user looking for the end of the str.
*/

char	*ft_strchr(const char *str, int a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)a)
			return ((char *)&str[i]);
		i++;
	}
	if (a == '\0')
	{
		return ((char *)&str[i]);
	}
	return (0);
}
/*
int main(void) {
    char *str = "Hola Mundo";
    printf(ft_strchr(str, 'M'));
    return (0);
}
*/

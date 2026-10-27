/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:31:30 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Searches for the last time a character appears in a string.
Starts from the end of the string using strlen and moves backwards.
Returns a pointer to the character
*/

char	*ft_strrchr(const char *str, int a)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)a)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
/*
int main(void) 
{
    char *str = "Hola Mundo";
    char *res;

    res = ft_strrchr(str, 'M');
    
    if (res)
        printf(str, res);
    else
        printf("Carácter no encontrado.\n");
        
    return (0);
}
*/
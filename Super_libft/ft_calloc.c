/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:58:11 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
Similar to malloc, saves memory for a given size and sets it to zero.
First do it with malloc, then error control, 
and finnaly calls bzero to set to zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count != 0 && (count * size) / count != size)
		return (NULL);
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
/*
int main(void) {
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (arr) {
        printf(arr[0]);
        printf(arr[4]);
        free(arr);
    }
    return (0);
}
*/

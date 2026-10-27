/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:47:14 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 13:19:34 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

char	*ft_strjoin_next_line(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, len);
	ft_strlcat(str, s2, len);
	free (s1);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:11:33 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/*
ft_count, counts the number of words in a strig.
Then in the main function, split a string into an array of strings, 
using a given character as a delimiter. 
*/

static int	ft_count(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static void	ft_fill_split(char const *s, char c, char **res)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	start = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		res[j] = ft_substr(s, start, i - start);
		j++;
	}
	res[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		start;
	int		j;

	i = 0;
	start = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof (char *) * (ft_count(s, c) + 1));
	if (res == NULL)
		return (NULL);
	ft_fill_split(s, c, res);
	return (res);
}
/*
int	main(void)
{
	char	*str;
	char	**res;
	int		i;

	str = "Hola Mundo 42";
	res = ft_split(str, ' ');
	i = 0;
	while (res[i] != NULL)
	{
		printf("%d: %s\n", i, res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}
*/

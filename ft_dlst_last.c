/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:04:58 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/15 21:04:58 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
// 	Return the last node of a list
//
// Parameters:
// 	First node list
//
// Retyrb value:
// 	Last node list

#include "libft.h"

t_node	*ft_dlstlast(t_node *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->next)
	{
		dlst = dlst->next;
	}
	return (dlst);
}
/*
int	main(void)
{
	t_node	*lst;

	lst = ft_lstnew("a");
	lst->next = ft_lstnew("b");
	lst->next->next = ft_lstnew("c");
	printf("lst: %p\n", (char *)lst);
	printf("lst2: %p\n", (char *)lst->next);
	printf("lst3: %p\n", (char *)lst->next->next);
	printf("\nLast: %p\n", ft_lstlast(lst));
	return (0);
}*/

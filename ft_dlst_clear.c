/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:57:35 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/15 20:57:35 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
// 	Delete and free node 'lst' and all consectuive nodes
// 	using 'del' and 'free()'
//
// Parameters:
// 	lst, ptr to a node
// 	del: ptr to a function used to delete the node content
//
// Return value:
// 	No value

#include "push_swap.h"

void	ft_lstclear(t_node **dlst)
{
	t_node	*temp;

	if (!dlst || !del)
		return ;
	while (*dlst)
	{
		temp = (*dlst)->next;
		free (*dlst);
		*dlst = temp;
	}
}
/*
int	main(void)
{
	t_list	*root;

	root = ft_lstnew(ft_("a"));
	root->next = ft_lstnew(("b"));
	root->next->next = ft_lstnew(("c"));
	ft_lstclear(&root, del);
	return(0);
}*/

/* ************************************************************************** */
/*	   	                                                                    */
/*                                                        :::      ::::::::   */
/*   ft_dlst_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:10:15 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/15 21:10:15 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Description:
//	Add node 'new' to the 'dlst' end
//
// Parameters:
// 	dlst, ptr to the first 'dlst' node
// 	new, ptr to a node added to the list
//

#include "push_swap.h"

void	ft_dlst_addback(t_stack *stack, t_node *new, char c)
{
	if (!head || !last || !new)
		return ;
	if (!*head)
	{
		*head = new;
		*last = new;
	}
	else
	{
		(*last)-> next = new;
		new -> prev = *last;
		*last = new;
	}
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*new;
	
	lst = ft_lstnew("a");
	new = ft_lstnew("b");
	n
	printf("lst: %p\nlst-n: %p\n\nnew: %p\nnew-n: %p\n", 
		lst, lst->next, new, new->next);
	ft_lstadd_back(&lst, new);
	printf("-------after\nlst: %p\nlst-next: %p\n lst-next-next: %p\n", 
		lst, lst->next, lst->next->next);
	return (0);
}*/

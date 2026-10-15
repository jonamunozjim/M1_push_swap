/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:50:02 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/15 20:50:02 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************************************************
 *								                                *
 * Description:							                        *
 * 	Allocate memory with malloc and generate a new node.	    *
 * 	'Value' is initalized with int 'value' parameter.	        *
 *	'Next' is initialized with NULL                             *
 *  'prev' is initialized with NULL                				*
 *								                                *
 *	Return value:						                        *
 *		Pointer to the new node.			                    *
 *								                                *
 ***************************************************************/

#include "push_swap.h"

t_node	*ft_dlstnew(int value)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node -> value = value;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}
/*
int	main(void)
{
	int	item[2];
	t_list	*list;

	item[0] = 0;
	item[1] = 1;
	list = ft_lstnew(item);
	printf("list.content: %i", ((int *)list->content)[0]);
	return (0);
}*/

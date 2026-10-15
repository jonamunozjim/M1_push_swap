/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:55:23 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/15 20:55:23 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Description:
//	Count number of nodes.
//
//Parameters:
//	lst: list head
//
//Return value:
//	List length
//
//

#include "push_swap.h"

unsigned int	ft_dlstsize(t_node *node)
{
	unsigned int	i;

	i = 0;
	while (node)
	{
		node = node -> next;
		i++;
	}
	return (i);
}

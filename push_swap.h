/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:37:41 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/15 20:37:41 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h> //For testing purpose only. To be deleted

typedef struct	s_node
{
	int	value;
	s_node	*next;
	s_node	*prev;
} t_node;

typedef struct	s_stacks
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*last_a;
	t_node	*last_b;
} t_stacks;

void	ft_dlst_addback(t_node **head, t_node **last, t_node *new)
void	ft_dlst_addfront(t_node **head, t_node **last, t_node *new)
void	ft_lstclear(t_node **dlst)
unsigned int	ft_dlstsize(t_node *node)
t_node	*ft_dlstnew(int value)
t_node	*ft_dlstlast(t_node *dlst)

#endif
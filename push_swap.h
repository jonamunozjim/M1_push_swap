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

typedef struct s_node
{
	int				value;
	int				index;
	int				chunk_index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stacks
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*last_a;
	t_node	*last_b;
}	t_stacks;

unsigned int	ft_dlstsize(t_node *node);
void			ft_dlstclear(t_node **dlst);
void			ft_push_a(t_stacks *stacks);
void			ft_push_b(t_stacks *stacks);
void			ft_push_a_b(t_stacks *stacks);
void			ft_swap_a(t_stacks *stacks, int write_flag);
void			ft_swap_b(t_stacks *stacks, int write_flag);
void			ft_swap_a_b(t_stacks *stacks);
void			ft_rotate_a(t_stacks *stacks, int write_flag);
void			ft_rotate_b(t_stacks *stacks, int write_flag);
void			ft_rotate_a_b(t_stacks *stacks);
void			ft_reverse_rotate_a(t_stacks *stacks, int write_flag);
void			ft_reverse_rotate_b(t_stacks *stacks, int write_flag);
void			ft_reverse_rotate_a_b(t_stacks *stacks);
int				ft_fill_nodes(t_stacks *stacks, int ac, char **av);
t_node			*ft_new_node(char **av, int i);
float			ft_disorder(t_stacks *stacks);
int				ft_is_valid(char *str);
int				ft_simple_sort(t_stacks *stacks);
t_node			*min_node(t_stacks *stack);
int			ft_medium_sort(t_stacks *stacks, int total_nodes);

#endif
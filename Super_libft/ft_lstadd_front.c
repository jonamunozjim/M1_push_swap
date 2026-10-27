/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 09:57:05 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *lista = ft_lstnew("Nodo original");
	t_list *nuevo_frente = ft_lstnew("Nuevio");
    
    ft_lstadd_front(&lista, nuevo_frente);
    printf("Primero: %s\n", (char *)lista->content);
    printf("Segundo: %s\n", (char *)lista->next->content);
    
    free(lista->next);
    free(lista);
    return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 10:43:49 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp -> next = new;
}
/*
int main(void)
{
    t_list *lista = ft_lstnew("Inicio");
    t_list *nuevo_final = ft_lstnew("Final");
    
    ft_lstadd_back(&lista, nuevo_final);
    
    printf("Primero: %s\n", (char *)lista->content);
    printf("Último: %s\n", (char *)lista->next->content);
    
    free(lista->next);
    free(lista);
    return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 10:37:18 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL && lst->next != NULL)
		lst = lst -> next;
	return (lst);
}
/*
int main(void)
{
    t_list *lista = ft_lstnew("Primero");
    lista -> next = ft_lstnew("Segundo");
    lista -> next -> next = ft_lstnew("Ultimo");
    
    t_list *ultimo = ft_lstlast(lista);
    if (ultimo)
        printf("El ultimo nodo contiene: %s\n", (char *)ultimo->content);
    
    free(lista->next->next);
    free(lista->next);
    free(lista);
    return (0);
}
*/

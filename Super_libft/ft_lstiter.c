/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:06:58 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 11:19:38 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	sumar(void *content)
{
	int	*num = (int *)content;
	*num = *num + 1;
}

int main(void)
{
    int	n1 = 10;
	int	n2 = 20;

	t_list *lista = ft_lstnew(&n1);
    ft_lstadd_back(&lista, ft_lstnew(&n2));
    ft_lstiter(lista, sumar);
    printf("Primero: %d\n", *(int *)lista -> content);
	printf("Segundo: %d\n", *(int *)lista -> next -> content);
    return (0);
}
*/

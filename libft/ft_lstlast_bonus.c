/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:50:55 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:29:51 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst-> next;
	}
	return (lst);
}

/* static void	ft_print_list(t_list *lst)
{
	int	node;
	node = 1;
	while (lst != NULL)
	{
		printf("nodo: %d, contenido: %p \n", node, lst->content);
		lst = lst->next;
		node++;
	}
}

int	main(void)
{
	t_list	*node1 = ft_lstnew("nodo 1");
	t_list	*node2 = ft_lstnew("nodo 2");
	t_list	*node3 = ft_lstnew("nodo 3");

	ft_lstadd_front(&node1, node2);
	ft_lstadd_front(&node1, node3);
	ft_print_list(node1);
	
	printf("puntero a ultimo nodo lista: %p \n", ft_lstlast(node1));
	return (0);
} */

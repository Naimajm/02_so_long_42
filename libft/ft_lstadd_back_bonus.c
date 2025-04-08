/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:17:34 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:29:21 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	if (!lst || !new_node)
		return ;
	last_node = ft_lstlast(*lst);
	if (!last_node)
	{
		*lst = new_node;
		return ;
	}
	last_node->next = new_node;
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
	printf("tamaño lista: %d \n", ft_lstsize(node1));

	t_list	*node4 = ft_lstnew("nodo 4");
	ft_lstadd_back(&node1, node4);
	
	printf("puntero a ultimo nodo añadido 'nodo4': %p \n", ft_lstlast(node1));
	ft_print_list(node1);
	printf("tamaño lista: %d \n", ft_lstsize(node1));
	return (0);
} */

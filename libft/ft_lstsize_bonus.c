/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:24:16 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:06 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
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
 	t_list *node1 = ft_lstnew("nodo 1");
	t_list *node2 = ft_lstnew("nodo 2"); 
	t_list *node3 = ft_lstnew("nodo 3"); 
	printf("node1 content: %p \n", node1->content);
	printf("node2 content: %p \n", node2->content);
	printf("node3 content: %p \n", node3->content);

	ft_lstadd_front(&node1, node2);
	ft_lstadd_front(&node1, node3);
	ft_print_list(node1);

	printf("tamaño lista: %d \n", ft_lstsize(node1));
	return (0);
} */

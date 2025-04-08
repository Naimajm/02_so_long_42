/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:06:55 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:29:26 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}

/* static void	ft_print_list(t_list *lst)
{
	int	node;
	node = 0;
	while (lst != NULL)
	{
		printf("nodo: %d, contenido: %p \n", node, lst->content);
		lst = lst->next;
		node++;
	}
}

int	main(void)
{
	t_list *new1 = ft_lstnew("str1");
	t_list *new2 = ft_lstnew("str2"); 
	printf("new1 content: %p \n", new1->content);
	printf("new2 content: %p \n", new2->content);

	ft_lstadd_front(&new1, new2);
	printf("nodo1 content: %p \n", new1->content);
	printf("nodo2 next->content: %p \n", new1->next->content);
	ft_print_list(new1);

	return (0);
} */
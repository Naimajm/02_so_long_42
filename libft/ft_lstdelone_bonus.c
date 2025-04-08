/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:11:01 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:29:39 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}

/* void ft_del_string (void *str)
{
  if(str)
  {
   free(str);
   str = 0;
  }
}

static void ft_print_list(t_list *lst)
{
	int	node;
	node = 1;
	printf("lista ---------- \n ");
	while (lst != NULL)
	{
		printf("nodo: %d, contenido: %p \n", node, lst->content);
		lst = lst->next;
		node++;
	}
} */

/* int main (void)
{
    char *str1 = malloc (2);
	str1[0] = '1';
	str1[1] = '\0';

    char *str2 = malloc (2);
	str2[0] = '2';
	str2[1] = '\0';

    char *str3 = malloc (2);
	str3[0] = '3';
	str3[1] = '\0';

	t_list	*node1 = ft_lstnew(str1);
	t_list	*node2 = ft_lstnew(str2);
	t_list	*node3 = ft_lstnew(str3);

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	ft_print_list(node1);

	ft_lstdelone(node2, ft_del_string);
	ft_print_list(node1);

	return(0);
} */

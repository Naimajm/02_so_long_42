/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:53:25 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:29:56 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*function)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !function || !del)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = function(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* static void ft_change_string (void *ptr)
{
   char *str_ptr;
	str_ptr = ptr;
	*str_ptr = *str_ptr + 1;
}

 void ft_del_string (void *str)
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
	char	*str_content;

	node = 0;
	printf("lista ---------- \n");
	while (lst != NULL)
	{	
		str_content = (char *)lst->content;
		printf("nodo: %d, contenido: %s \n", node, str_content);
		lst = lst->next;
		node++;
	}
}

int main (void)
{
    char *str1 = malloc (2);
	str1[0] = '1';
    char *str2 = malloc (2);
	str2[0] = '2';
    char *str3 = malloc (2);
	str3[0] = '3';
	t_list	*new_list;

	t_list	*node1 = ft_lstnew(str1);
	t_list	*node2 = ft_lstnew(str2);
	t_list	*node3 = ft_lstnew(str3);

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	printf("lista original \n");
	ft_print_list(node1);

	new_list = ft_lstmap(node1, (void *)ft_change_string, ft_del_string);
	printf("Nueva lista \n");
	ft_print_list(new_list);
	return(0);
} */

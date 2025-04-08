/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:10:42 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int	main(void)
{
	t_list	*lista = ft_lstnew("Hola");
	printf ("ft_lstnew return -> %p \n", lista);
	printf ("ft_lstnew content -> %p \n", lista->content);
	printf ("ft_lstnew  next -> %p \n", lista->next);
	return (0);
} */
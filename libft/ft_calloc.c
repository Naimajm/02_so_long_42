/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:44:08 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:28:23 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	index;

	index = 0;
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (index < count * size)
	{
		ptr[index] = 0;
		index++;
	}
	return ((void *)ptr);
}

/* int	main(int argn, char **argv)
{
	unsigned int	count = argv[1][0] -'0';
	unsigned int	size = argv[2][0] -'0';
	
    if (argn > 2)
	{
		printf("argumentos -> count '%d' size '%d' \n", count, size);
		printf("ft_calloc -> return %s \n", (char *)ft_calloc(count, size));
	}  
    return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:54:15 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:28:12 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dest, size_t len)
{
	char	*dest_ptr;
	size_t	index;

	dest_ptr = (char *)dest;
	index = 0;
	if (len != 0)
	{
		while (index < len)
		{
			dest_ptr[index] = 0;
			index++;
		}
	}
	return ((void *)dest);
}

/* int	main(int argn, char **argv)
{
	char	*dest = argv[1];
	int	len = argv[2][0] - '0';
	
    if (argn > 2)
	{
		printf("argumentos -> dest '%s' , len '%d' \n"
			, dest, len);
		printf("ft_bzero -> return %s \n", 
            (char *) ft_bzero(dest, len));
	}  
    return (0);
} */
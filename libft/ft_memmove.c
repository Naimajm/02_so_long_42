/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:53:51 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:26 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int num)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if ((src == NULL && dest == NULL) || (dest == src))
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest > src)
		while (num-- > 0)
			dest_ptr[num] = src_ptr[num];
	else
		ft_memcpy(dest, src, num);
	return (dest_ptr);
}

/* int	main(int argn, char **argv)
{
	char	*dest = argv[1];
	char	*src = argv[2];
	int	num = argv[3][0] - '0';
	
    if (argn > 3)
	{
		printf("argumentos -> dest '%s' , src '%s' , num '%d' \n"
			, dest, src, num);
		printf("ft_memmove -> return %s \n", 
            (char *) ft_memmove(dest, src, num));
	}  
    return (0);
} */
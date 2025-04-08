/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:27:43 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:21 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int num)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	unsigned int	index;

	if (src == NULL && dest == NULL)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	index = 0;
	while (index < num)
	{
		dest_ptr[index] = src_ptr[index];
		index++;
	}
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
		printf("ft_memcpy -> return %s \n", 
            (char *) ft_memcpy(dest, src, num));
	}  
    return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:32:57 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:30 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int character, unsigned int len)
{
	unsigned char	*dest_ptr;
	unsigned int	index;

	dest_ptr = (unsigned char *)dest;
	index = 0;
	while (index < len)
	{
		dest_ptr[index] = (unsigned char)character;
		index++;
	}
	return (dest);
}

/* int	main(int argn, char **argv)
{
	char	*dest = argv[1];
	char	character = argv[2][0];
	int	len = argv[3][0] - '0';
	
    if (argn > 3)
	{
		printf("argumentos -> dest '%s' , character '%c' , len '%d' \n"
			, dest, character, len);
		printf("ft_memset -> return %s \n", 
            (char *)ft_memset(dest, character, len));
	}  
    return (0);
} */

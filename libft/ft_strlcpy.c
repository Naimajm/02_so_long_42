/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:11:58 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:41 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char const *src, unsigned int destsize)
{
	unsigned int	index;
	unsigned int	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (destsize != 0)
	{
		while ((src[index] != '\0' && index < (destsize - 1)))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (src_len);
}

/* int main(int argn, char **argv)
{
	char	*dest = argv[1];
	char	*src = argv[2];
	unsigned int size = argv[3][0] - '0';

    if (argn > 3)
	{
		printf("argumentos -> dest '%s' , src '%s' , size %d \n"
			, dest, src, size);
		printf("ft_strlcpy -> return %d , dest : '%s' \n"
			, ft_strlcpy(dest, src, size), dest);
	}  
    return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:43:09 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:37 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int destsize)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	dest_index;
	unsigned int	src_index;

	src_len = (unsigned int) ft_strlen(src);
	dest_len = (unsigned int) ft_strlen(dest);
	src_index = 0;
	dest_index = dest_len;
	if (!dest || destsize <= dest_len)
		return (destsize + src_len);
	while (src[src_index] != '\0' && dest_index < (destsize - 1))
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (dest_len + src_len);
}

/* int main(int argn, char **argv)
{
	char	*dest = argv[1];
	char	*src = argv[2];
	unsigned int size = argv[3][0] - '0';
	//unsigned int size = 20;

    if (argn > 2)
	{
		printf("argumentos -> dest '%s' , src '%s' , size %d \n"
			, dest, src, size);
		printf("ft_strlcat -> return %d , dest : '%s' \n"
			, ft_strlcat(dest, src, size), dest);
	}  
    return (0);
} */

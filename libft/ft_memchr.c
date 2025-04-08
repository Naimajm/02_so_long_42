/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:57:22 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:10 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int character, unsigned int num)
{
	unsigned char	*str_ptr;
	unsigned char	chr;
	unsigned int	index;

	str_ptr = (unsigned char *) str;
	chr = (unsigned char) character;
	index = 0;
	while (index < num)
	{
		if (str_ptr[index] == chr)
		{
			return ((void *)(str_ptr + index));
		}
		index++;
	}
	return (NULL);
}

/* int	main(int argn, char **argv)
{
	char	*str = argv[1];
	char	character = argv[2][0];
	int	num = argv[3][0] - '0';
	
    if (argn > 3)
	{
		printf("argumentos -> str '%s' , character '%c' , num '%d' \n"
			, str, character, num);
		printf("ft_memchr -> return %s \n", 
            (char *) ft_memchr(str, character, num));
	}  
    return (0);
} */

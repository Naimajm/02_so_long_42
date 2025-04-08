/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:00:10 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:16 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, unsigned int num)
{
	unsigned char	*str1_ptr;
	unsigned char	*str2_ptr;
	unsigned int	index;

	str1_ptr = (unsigned char *) str1;
	str2_ptr = (unsigned char *) str2;
	index = 0;
	if (num == 0)
		return (0);
	while (index < num)
	{
		if (str1_ptr[index] == str2_ptr[index])
			index++;
		else if (str1_ptr[index] > str2_ptr[index])
			return (1);
		else
			return (-1);
	}
	return (0);
}

/* int	main(int argn, char **argv)
{
	char	*str1 = argv[1];
	char	*str2 = argv[2];
	int	num = argv[3][0] - '0';
	
    if (argn > 3)
	{
		printf("argumentos -> str1 '%s' , str2 '%s' , num '%d' \n"
			, str1, str2, num);
		printf("ft_memcmp -> return %d \n", 
            ft_memcmp(str1, str2, num));
	}  
    return (0);
} */

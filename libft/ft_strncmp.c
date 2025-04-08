/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:44:26 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:55 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, unsigned int num)
{
	unsigned char	*str1_ptr;
	unsigned char	*str2_ptr;
	unsigned int	indice;

	str1_ptr = (unsigned char *) str1;
	str2_ptr = (unsigned char *) str2;
	indice = 0;
	if (num == 0)
		return (0);
	while ((indice < num)
		&& (str1_ptr[indice] != '\0' || str2_ptr[indice] != '\0'))
	{
		if (str1_ptr[indice] == str2_ptr[indice])
			indice++;
		else if (str1_ptr[indice] > str2_ptr[indice])
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
		printf("ft_strncmp -> return %d \n", ft_strncmp(str1, str2, num));
	}  
    return (0);
} */
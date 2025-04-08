/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:43:50 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:18 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	unsigned char	chr;
	unsigned int	indice;

	chr = (unsigned char) character;
	indice = 0;
	while (str[indice])
	{
		if (str[indice] == chr)
			return ((char *)(str + indice));
		indice++;
	}
	if (str[indice] == '\0' && str[indice] == chr)
		return ((char *)(str + indice));
	return (0);
}

/* int main(int argn, char **argv)
{
	char	*str = argv[1];
	char	character = argv[2][0];
	
    if (argn > 2)
	{
		printf("argumentos -> str '%s' , character '%c' \n"
			, str, character);
		printf("ft_strchr -> return %s \n", ft_strchr(str, character));
	}  
    return (0);
} */

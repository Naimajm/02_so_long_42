/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:23:51 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:32:04 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	unsigned char	chr;
	unsigned int	len;

	len = (unsigned int) ft_strlen(str);
	chr = (unsigned char) character;
	if (str[len] == '\0' && str[len] == chr)
		return ((char *)(str + len));
	while (len > 0)
	{
		if (str[len - 1] == chr)
			return ((char *)(str + (len - 1)));
		len--;
	}
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
		printf("ft_strrchr -> return %s \n", ft_strrchr(str, character));
	}  
    return (0);
} */

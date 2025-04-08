/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:56:34 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:32:13 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, unsigned int len)
{
	unsigned int	str_len;
	unsigned int	substr_index;
	unsigned char	*substr;

	str_len = ft_strlen(str);
	substr_index = 0;
	if (!str)
		return (NULL);
	if (start > str_len)
		return (ft_strdup(""));
	if ((start + len) > str_len)
		len = str_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (substr_index < len)
	{
		substr[substr_index] = str[start + substr_index];
		substr_index++;
	}
	substr[substr_index] = '\0';
	return ((char *)substr);
}

/* int	main(int argn, char **argv)
{
	char	*str = argv[1];
	int	start = argv[2][0] - '0';
	int	len = argv[3][0] - '0';
	
    if (argn > 2)
	{
		printf("argumentos -> dest '%s' , num '%d' , num '%d' \n"
			, str, start, len);
		printf("ft_substr -> return %s \n", ft_substr(str, start, len));
	}  

		printf("argumentos -> dest '%s' , num '%d' , num '%d' \n"
			, "Hola Mundo", 2, 4);
		printf("ft_substr -> return %s \n", ft_substr("Hola Mundo", 2, 4));

		printf("argumentos -> dest '%s' , num '%d' , num '%d' \n"
			, "Hola", 9, 4);
		printf("ft_substr -> return %s \n", ft_substr("Hola", 9, 4));

		printf("argumentos -> dest '%s' , num '%d' , num '%d' \n"
			, "Hola", 2, 4);
		printf("ft_substr -> return %s \n", ft_substr("Hola", 2, 4));

    return (0);
} */

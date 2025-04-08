/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:25:29 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:32 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	unsigned char	*str;
	unsigned int	str1_len;
	unsigned int	str2_len;
	unsigned int	str1_index;
	unsigned int	str2_index;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	str1_index = 0;
	str2_index = 0;
	str = malloc(str1_len + str2_len + 1);
	if (!str || (!str1 && !str2))
		return (NULL);
	while (str1[str1_index] != '\0')
	{
		str[str1_index] = str1[str1_index];
		str1_index++;
	}
	while (str2[str2_index] != '\0')
	{
		str[str1_index + str2_index] = str2[str2_index];
		str2_index++;
	}
	str[str1_index + str2_index] = '\0';
	return ((char *) str);
}

/* int main(int argn, char **argv)
{
	char	*str1 = argv[1];
	char	*str2 = argv[2];
	
    if (argn > 2)
	{
		printf("argumentos -> str1 '%s' , str2 '%s' \n"
			, str1, str2);
		printf("ft_strjoin -> return %s \n", ft_strjoin(str1, str2));
	}  
    return (0);
} */

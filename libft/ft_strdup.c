/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:19:29 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:23 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	len;
	unsigned char	*dest;

	len = ft_strlen(str);
	dest = malloc((size_t)(len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy((char *)dest, str, len + 1);
	return ((char *)dest);
}

/* int	main(int argn, char **argv)
{
	char	*str = argv[1];
	
    if (argn > 1)
	{
		printf("argumentos -> str '%s' \n", str);
		printf("ft_strdup -> return %s \n", ft_strdup(str));
	}  
    return (0);
} */

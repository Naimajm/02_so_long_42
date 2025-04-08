/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:23:14 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:32:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *toFind, size_t num)
{
	char	*src_ptr;
	size_t	src_i;		
	size_t	tofind_j;

	src_ptr = (char *) src;
	src_i = 0;
	if (toFind[0] == 0)
		return (src_ptr);
	while (src[src_i] != '\0' && src_i < num)
	{
		tofind_j = 0;
		while ((src[src_i + tofind_j] == toFind[tofind_j])
			&& src[src_i + tofind_j] != '\0'
			&& ((src_i + tofind_j) < num))
		{
			tofind_j++;
			if (toFind[tofind_j] == 0)
				return ((char *)(src + src_i));
		}
		src_i++;
	}
	return (0);
}

/* int	main(int argn, char **argv)
{
	char	*src = argv[1];
	char	*toFind = argv[2];
	int	num = argv[3][0] - '0';
	
    if (argn > 3)
	{
		printf("argumentos -> src '%s' , toFind '%s' , num '%d' \n"
			, src, toFind, num);
		printf("ft_strnstr -> return %s \n", ft_strnstr(src, toFind, num));
	}  
    return (0);
} */

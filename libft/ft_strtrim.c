/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:50:36 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:32:09 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str1, char const *set)
{
	unsigned char	*strtrim;
	unsigned int	init_index;
	unsigned int	end_index;

	init_index = 0;
	end_index = ft_strlen(str1);
	if (!str1)
		return (ft_strdup(""));
	while (ft_strchr(set, str1[init_index]))
		init_index++;
	while (end_index > 0 && ft_strchr(set, str1[end_index]))
		end_index--;
	strtrim = (unsigned char *)
		ft_substr(str1, init_index, (end_index - init_index + 1));
	return ((char *) strtrim);
}

/* int	main(void)
{
	printf("'1234', '12' // '34' --> %s \n", ft_strtrim("1234", "12"));

	printf("'xyaybyz', 'xyz' // 'ayb' --> %s \n", ft_strtrim("xyaybyz", "xyz"));

	printf("'1234', ''// '1234'--> %s \n", ft_strtrim("1234",""));	

	printf("'12', '1234' // '' --> %s \n", ft_strtrim("12","1234"));
		
	printf("'', '12' // '' --> %s \n", ft_strtrim("","12"));
	
	printf("'', '' // '' --> %s \n", ft_strtrim("",""));	

	return (0);
} */

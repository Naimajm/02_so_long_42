/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:07:14 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:45 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen(char const *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

/* int main(int argn, char **argv)
{
    if (argn > 1)
        printf("ft_strlen '%s' : %d \n", argv[1], ft_strlen(argv[1]));

    printf("strlen '%s' : %ld \n", "HolaCla", strlen("HolaCla"));
    printf("ft_strlen '%s' : %d \n", "HolaCla", ft_strlen("HolaCla"));
    return (0);
} */

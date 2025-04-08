/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:20:14 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:28:38 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int caracter)
{
	int	is_ascii;

	is_ascii = 0;
	if (caracter >= 0 && caracter <= 127)
		is_ascii = 1;
	return (is_ascii);
}

/* int main(int argn, char **argv)
{
    if (argn > 1)
        printf("caracter '%c' : %d \n", argv[1][0], ft_isascii(argv[1][0]));

    printf("caracter ascii '-': %d \n", ft_isascii('-'));
    printf("caracter ascii '164': %d \n", ft_isascii(164));
    return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:57:41 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 20:52:58 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char character)
{
	write(1, &character, 1);
	return (1);
}

/* int	main(int argn, char **argv)
{
	char caracter = argv[1][0];
    int num = ft_putchar(caracter);
	if (argn > 1)
		printf("\n num caracteres impresos: %d \n",num);
	return (0);
} */
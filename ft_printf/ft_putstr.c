/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:19:52 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 20:52:29 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putstr(char *str)
{
	int	index;
	int	chars_number;

	index = 0;
	chars_number = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[index] != '\0')
	{
		chars_number += ft_putchar(str[index]);
		index++;
	}
	return (chars_number);
}

/* int	main(int argn, char **argv)
{
	int num = ft_putstr(argv[1]);
	if (argn > 1)
		printf("\n num caracteres impresos: %d \n",num);
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:18:36 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 20:53:03 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_address(unsigned long long num);

int	ft_putaddress(unsigned long long ptr_address)
{
	int	chars_number;

	chars_number = 0;
	if (ptr_address == 0)
		return (ft_putstr("(nil)"));
	chars_number += ft_putstr("0x");
	chars_number += ft_puthex_address(ptr_address);
	return (chars_number);
}

static int	ft_puthex_address(unsigned long long num)
{
	unsigned int	chars_number;
	char			*base_hexa;

	chars_number = 0;
	base_hexa = "0123456789abcdef";
	if (num >= 16)
		chars_number += ft_puthex_address(num / 16);
	chars_number += ft_putchar(base_hexa[num % 16]);
	return (chars_number);
}

/* int main(void)
{   
    size_t ptr_address = 452397;
    char *str = NULL;

    int num_ptraddress = ft_putaddress(ptr_address);

    printf("\n argumentos -> void * '%p' \n", str);
    printf("num caracteres impresos: %d \n", num_ptraddress);
    return (0);
} */
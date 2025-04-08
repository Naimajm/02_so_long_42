/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:58:05 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 20:52:18 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int num)
{
	int	chars_number;

	chars_number = 0;
	if (num > 9)
	{
		chars_number += ft_putunsigned(num / 10);
		chars_number += ft_putunsigned(num % 10);
	}
	else
		chars_number += ft_putchar(num + '0');
	return (chars_number);
}

/* int	main(void)
{	
	// NUMEROS ENTEROS SIN SIGNO 'UNSIGNED INT' -> especificador de formato %u
	printf("NUMEROS ENTEROS SIN SIGNO (unsigned int) 'u' \n");
	
	unsigned int unsig_int0 = 0;
	int resultado1 = printf("%u\n", unsig_int0);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	
	int resultado = ft_printf("%u\n", unsig_int0);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	unsigned int unsig_int1 = 567845;
	resultado1 = printf("%u\n", unsig_int1);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	
	resultado = ft_printf("%u\n", unsig_int1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	return (0);
} */
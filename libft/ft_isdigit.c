/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:52:46 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:28:43 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int digit)
{
	int	is_digit;

	is_digit = 0;
	if (digit >= '0' && digit <= '9')
		is_digit = 1;
	return (is_digit);
}

/* int    main(int argn, char **argv)
{
	if (argn > 1)
		printf("caracter '%c' : %d \n", argv[1][0], ft_isdigit(argv[1][0]));
    return (0);
} */

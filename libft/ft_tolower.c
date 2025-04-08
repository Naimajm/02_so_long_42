/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:33:17 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:32:19 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (character + 32);
	return (character);
}

/* int    main(int argn, char **argv)
{
	if (argn > 1)
		printf("caracter '%c': %c \n", argv[1][0], ft_tolower(argv[1][0]));
    return (0);
} */

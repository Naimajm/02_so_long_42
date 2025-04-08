/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:16:00 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:28:33 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int charac)
{
	int	is_alpha;

	is_alpha = 0;
	if ((charac >= 'A' && charac <= 'Z') || (charac >= 'a' && charac <= 'z'))
		is_alpha = 1;
	return (is_alpha);
}

/* int    main(int argn, char **argv)
{
	if (argn > 1)
		printf("caracter alfa '%c': %d \n", argv[1][0], ft_isalpha(argv[1][0]));
    return (0);
} */

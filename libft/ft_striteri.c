/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:26:11 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:28 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*function)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (str && function)
	{
		while (str[index] != '\0')
		{
			(*function)(index, str + index);
			index++;
		}
	}
}

/* void ft_funcionprueba(unsigned int index, char *character)
{
	character = character + index;
}

int main(int argn, char **argv)
{
	char	*str = argv[1];
	
    if (argn > 1)
	{
		printf("argumentos -> str '%s' \n", str);
		ft_striteri(str, ft_funcionprueba);
		printf("ft_striteri -> return %s \n", str);
	}  
    return (0);
} */

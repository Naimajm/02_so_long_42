/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:01:26 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:49 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	index;

	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			write(fd, &str[index], 1);
			index++;
		}
	}
}

/* int	main(void)
{
	int fd = open("text.txt", O_RDWR);
	ft_putstr_fd("Hola Mundo", fd);
	close(fd);
	return (0);
} */
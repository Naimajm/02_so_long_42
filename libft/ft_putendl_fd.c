/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:17:40 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:39 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
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
		write(fd, "\n", 1);
	}
}

/* int	main(void)
{
	int	fd = open("text.txt", O_RDWR);
	ft_putendl_fd("Ey Mundo", fd);
	close(fd);
	return (0);
} */
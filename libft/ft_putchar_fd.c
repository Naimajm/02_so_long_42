/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:09:55 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:34 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char character, int fd)
{
	write (fd, &character, 1);
}

/* int	main(void)
{
	int	fd = open("text.txt", O_RDWR);	
	ft_putchar_fd('J', fd);
	close(fd);
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:04:19 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:30:44 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	if (num == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * -1;
		ft_putnbr_fd(num, fd);
	}
	else if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
	{
		ft_putchar_fd(num + '0', fd);
	}
}

/* int	main(void)
{
	int fd = open("text.txt", O_RDWR);

	//ft_putnbr_fd(-2147483648, fd);

	ft_putnbr_fd(-452, fd);

	//ft_putnbr_fd(452, fd);

	///ft_putnbr_fd(0, fd);

	close(fd);
	return (0);
} */
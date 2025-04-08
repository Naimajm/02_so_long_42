/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:41:23 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 20:53:34 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putnbr(int num);

int	ft_putaddress(unsigned long long ptr_address);

int	ft_puthexa(unsigned int num, char specifier_format);

int	ft_putunsigned(unsigned int num);

int	ft_putstr(char *str);

int	ft_putchar(char character);

#endif

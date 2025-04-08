/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:55:45 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:29:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int num);
static char	*ft_itoa_int_min(void);

char	*ft_itoa(int num)
{
	unsigned int	len;
	unsigned char	*result;

	if (num == -2147483648)
		return (ft_itoa_int_min());
	len = ft_int_len(num);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		result[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return ((char *)result);
}

static int	ft_int_len(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num = num * -1;
		count++;
	}
	if (num == 0)
		count++;
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_int_min(void)
{
	char	*result;

	result = (char *)malloc(12);
	if (!result)
		return (NULL);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

/* int	main(void)
{	
	printf("numero digitos del numero '-2147483648': %d  \n", 
		ft_int_len(-2147483648));
	printf("test funcion ft_itoa_int_min '-2147483648': %s  \n", 
		ft_itoa_int_min());

	printf("numero digitos del numero '-4543': %d  \n", ft_int_len(-4543));

	printf("string del numero '-2147483648': %s \n", ft_itoa(-2147483648));

	printf("string del numero '-4543': %s \n", ft_itoa(-4543));

	printf("string del numero '0': %s \n", ft_itoa(0));

	printf("string del numero '9': %s \n", ft_itoa(9));

	printf("string del numero '4543': %s \n", ft_itoa(4543));
	return (0);
} */

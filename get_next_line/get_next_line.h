/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:19:01 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/31 19:50:46 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlcpy_next_line(char *dest,
			const char *src, unsigned int destsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *str1, char const *str2);
int		ft_strlen_n(const char *str);
char	*ft_strchr(const char *str, int character);

#endif
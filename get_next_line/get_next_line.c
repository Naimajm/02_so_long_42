/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:59:55 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/17 21:50:23 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_final_part_line(char *total_line)
{
	int		buffer;
	int		index_final_line;
	char	*final_l;

	buffer = 0;
	index_final_line = 0;
	while (total_line[buffer] != '\0' && total_line[buffer] != '\n')
		buffer++;
	if (!total_line[buffer])
	{
		free(total_line);
		return (NULL);
	}
	final_l = ft_calloc(ft_strlen_n(total_line) - buffer + 1, sizeof(char));
	if (!final_l)
		return (NULL);
	while (total_line[buffer] != '\0')
	{
		final_l[index_final_line] = total_line[buffer + 1];
		buffer++;
		index_final_line++;
	}
	final_l[index_final_line] = '\0';
	free(total_line);
	return (final_l);
}

static char	*get_cleaned_line(char *buffer)
{
	int		index;
	char	*new_line;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] != '\0' && buffer[index] != '\n')
		index++;
	new_line = ft_calloc(index + 1 + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	ft_strlcpy_next_line(new_line, buffer, index + 1 + 1);
	return (new_line);
}

static char	*ft_strjoin_buffer_src(char	*buffer, char	*partial_line)
{
	char	*dest;

	if (!buffer && !partial_line)
		return (NULL);
	dest = ft_strjoin(buffer, partial_line);
	free(buffer);
	return (dest);
}

static char	*read_file(int fd, char *total_line)
{
	int		char_to_read;
	char	*buffer;

	if (total_line == NULL)
		total_line = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	char_to_read = 1;
	while (char_to_read > 0)
	{
		char_to_read = read(fd, buffer, BUFFER_SIZE);
		if (char_to_read == -1)
		{
			free(total_line);
			free(buffer);
			return (NULL);
		}
		buffer[char_to_read] = '\0';
		total_line = ft_strjoin_buffer_src(total_line, buffer);
		if (ft_strchr(total_line, '\n'))
			break ;
	}
	free(buffer);
	return (total_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = get_cleaned_line(buffer);
	buffer = get_final_part_line(buffer);
	return (next_line);
}

/* 
# include <stdio.h>

int	main(void)
{
	int		fd = open("text_00.txt", O_RDONLY);
	
	int index_read;
	char	*buffer;
	char	*new_line;
	char	*final_line;

	// 1º COPIAR LINEA COMPLETA HASTA L BUFFER QUE 
	// INCLUYE SALTO LINEA -> READ_FILE()
	index_read = read(fd, malloc(10 + 1), 10);
	buffer = read_file(fd, buffer);
	//printf("tamaño buffer -> %d \n", index_read);
	//printf("Linea bruta -> %s<-final\n", buffer);

	// 2º CONSEGUIR LINEA NETA HASTA SALTO LINEA -> GIVE_LINE()
	new_line = give_line(buffer);
	//printf("Linea neta -> %s \n", new_line);

	// 3º CONSEGUIR FINAL LINEA TEXTO DESPUES DE SALTO LINEA
	final_line = get_final_line(buffer);
	printf("final linea -> %s \n", final_line);

	free(buffer);
	free(new_line);
	free(final_line);

	// 4º TEST FUNCION GET_NEXT_LINE COMPLETA
	char	*next_line;
	int     count_line;

	count_line = 0;
	if (fd == -1) 
    {
        printf("Error al abrir archivo");
        return (1);
    }
	while ((next_line = get_next_line(fd)))
	{
		count_line++;
		printf("[%d]-> %s\n",count_line, next_line);
		free(next_line);
	}
	if (close(fd) == -1)
	{
        printf("Error al cerrar archivo");
        return (1);
    }
	return (0);
} */

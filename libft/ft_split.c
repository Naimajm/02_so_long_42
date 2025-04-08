/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:03:18 by juagomez          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:10 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *str, char character);
static int	ft_word_len(char const *str, char character, int index);
static char	**ft_free_array(char **array);
static char	**ft_split_words(char const *str, char c, char **ar, int w_num);

char	**ft_split(char const *str, char character)
{
	char			**array;
	unsigned int	words_numbers;

	if (!str)
		return (0);
	words_numbers = ft_words_count(str, character);
	array = (char **)malloc(sizeof(char *) * (words_numbers + 1));
	if (!array)
		return (0);
	array = (char **)ft_split_words
		(str, character, (char **)array, words_numbers);
	if (!array)
	{
		array = (char **)ft_free_array((char **)array);
		return (0);
	}
	return (array);
}

static char	**ft_split_words(char const *str, char c, char **arr, int w_num)
{
	int	str_index;
	int	word_index;
	int	word_len;

	str_index = 0;
	word_index = 0;
	while (word_index < w_num)
	{
		while (str[str_index] != '\0' && str[str_index] == c)
			str_index++;
		word_len = ft_word_len(str, c, str_index);
		arr[word_index] = ft_substr(str, str_index, word_len);
		if (!arr[word_index])
		{
			arr = ft_free_array((char **)arr);
			return (0);
		}
		str_index = str_index + word_len;
		word_len = 0;
		word_index++;
	}
	arr[word_index] = 0;
	return (arr);
}

static char	**ft_free_array(char **array)
{
	int	index;

	index = 0;
	if (array)
	{
		while (array[index])
		{
			free(array[index]);
			array[index] = 0;
			index++;
		}
		free(array);
		array = 0;
	}
	return (array);
}

static int	ft_word_len(char const *str, char character, int index)
{
	int	word_len;

	word_len = 0;
	while (str[index] != '\0' && str[index] != character)
	{
		index++;
		word_len++;
	}
	return (word_len);
}

static int	ft_words_count(char const *str, char character)
{
	int	index;
	int	count;
	int	word_flag;

	index = 0;
	count = 0;
	word_flag = 0;
	while (str[index] != '\0')
	{
		if (str[index] != character && word_flag == 0)
		{
			word_flag = 1;
			count++;
		}
		else if (str[index] == character)
			word_flag = 0;
		index++;
	}
	return (count);
}

/* int	main(void)
{
	printf("contador palabras string '3': %d \n", 
		ft_words_count("HOLA-CAT-BC", '-'));
	printf("contador palabras string '3': %d \n", 
		ft_words_count("-  HOLA-CAT-BC", '-'));
	printf("contador palabras string '3': %d \n", 
		ft_words_count("---HOLA-CAT-BC--", '-'));

	printf("longitud palabras: %d \n", ft_word_len("HOLA-CAT-BC", '-', 0));

	// TEST FUNCION FT_SPLIT 1
	int index = 0;
	char	**array = ft_split("HOLA-CAT-BC", '-');
	while (array[index])
	{
		printf("array palabras: %s \n", array[index]);
		index++;
	}
	// LIMPIEZA MEMORIA ARRAY TEST
	array = ft_free_array(array);
	if (array)
        printf("\n -ARRAY NO ES NULO- \n");

	// TEST FUNCION FT_SPLIT 2
	char	**array2 = ft_split("-  HOLA-CAT-BC", '-');
	while (array2[index])
	{
		printf("array palabras: %s \n", array2[index]);
		index++;
	}
	// LIMPIEZA MEMORIA ARRAY TEST
	array2 = ft_free_array(array2);
	if (array2)
        printf("\n -ARRAY NO ES NULO- \n");
	return (0);
} */
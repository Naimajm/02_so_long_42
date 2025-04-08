/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:19 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/15 01:37:55 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int				ft_isalpha(int caracter);

int				ft_isdigit(int digit);

int				ft_isalnum(int caracter);

int				ft_isascii(int caracter);

int				ft_isprint(int caracter);

void			*ft_bzero(void *dest, size_t len);

void			*ft_memset(void *dest, int caracter, unsigned int len);

void			*ft_memcpy(void *dest, const void *src, unsigned int n);

void			*ft_memmove(void *dest, const void *src, unsigned int num);

void			*ft_memchr(const void *str, int caracter, unsigned int num);

int				ft_memcmp(const void *str1, const void *str2, unsigned int num);

void			*ft_calloc(size_t count, size_t size);

char			*ft_strdup(const char *str);

char			*ft_substr(char const *str, unsigned int start,
					unsigned int len);

char			*ft_strjoin(char const *str1, char const *str2);

char			*ft_strtrim(char const *str1, char const *set);

char			*ft_strmapi(char const *str,
					char (*function)(unsigned int, char));

void			ft_striteri(char *str, void (*function)(unsigned int, char *));

int				ft_toupper(int character);

int				ft_tolower(int character);

unsigned int	ft_strlen(const char *string);

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int destsize);

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int destsize);

char			*ft_strchr(const char *str, int character);

char			*ft_strrchr(const char *str, int character);

int				ft_strncmp(const char *str1,
					const char *str2, unsigned int num);

char			*ft_strnstr(const char *src, const char *toFind, size_t num);

int				ft_atoi(const char *str);

char			*ft_itoa(int num);

char			**ft_split(char const *str, char character);

void			ft_putchar_fd(char character, int fd);

void			ft_putstr_fd(char *str, int fd);

void			ft_putendl_fd(char *str, int fd);

void			ft_putnbr_fd(int num, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;	
}				t_list;

t_list			*ft_lstnew(void *content);

int				ft_lstsize(t_list *lst);

void			ft_lstadd_front(t_list **lst, t_list *new_node);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new_node);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*function)(void *));

t_list			*ft_lstmap(t_list *lst,
					void *(*function)(void *), void (*del)(void *));

#endif
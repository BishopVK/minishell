/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:59:20 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/20 13:22:15 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//isascii, isalnum, tolower, toupper...
//# include <ctype.h>

//O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC...
//# include <fcntl.h>

//NULL, size_t
//# include <stddef.h>

//ft_printf
//# include <stdio.h>

//int8_t, int16_t, int32_t, uint8_t, uint16_t, uint32_t.
//Limits of: size_t, sig_atomic_t...
# include <stdint.h>

//malloc, calloc, free
# include <stdlib.h>

//atoi, memcpy, strchr...
//# include <string.h>

//bzero
//# include <strings.h>

//close, read, write
//# include <unistd.h>

//INT_MAX, INT_MIN, LLONG_MAX, LLONG_MIN
# include <limits.h>

// ft_printf, ft_dprintf
# include "printf/ft_printf.h"

// get_next_line
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_atoi(const char *nptr);
char			*ft_strdup(const char *s);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strstr(char *haystack, char *needle);
//size_t		*ft_strcspn(const char *s, const char *reject);
int				ft_strchr_int(const char *s, int c);
long long int	ft_custom_atoll(const char *nptr);

#endif
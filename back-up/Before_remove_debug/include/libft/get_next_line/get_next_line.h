/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:29:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/07 11:29:37 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//read, close
# include <unistd.h>

//open
# include <fcntl.h>

//printf
# include <stdio.h>

//malloc, free
# include <stdlib.h>

//NULL
# include <stddef.h>

//libft
# include "../libft.h"

//strchr, strlen, strdup, strlcpy
//# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef enum s_bool
{
	t_false,
	t_true,
}	t_bool;

/****************************************/
/*			get_next_line.c				*/
/****************************************/
char	*get_next_line(int fd, t_bool free_static);

/****************************************/
/*			get_next_line_utils.c		*/
/****************************************/
/* char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size); */

#endif
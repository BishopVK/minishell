/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:09:47 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/20 13:23:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//va_list, va_start, va_arg, va_end
# include <stdarg.h>

//printf
# include <stdio.h>

//write
# include <unistd.h>

/****************************************/
/*				ft_printf.c				*/
/****************************************/
int	ft_printf(char const *format, ...);

/****************************************/
/*				ft_dprintf.c			*/
/****************************************/
int	ft_dprintf(int fd, char const *format, ...);

/****************************************/
/*			ft_conversions.c			*/
/****************************************/
int	ft_conversions(va_list args, char *format, size_t *ctr, int fd);

/****************************************/
/*			ft_printf_utils.c			*/
/****************************************/
int	ft_putchar_printf(char c, size_t *ctr, int fd);
int	ft_putnbr_printf(int n, size_t *ctr, int fd);
int	ft_putstr_printf(char *str, size_t *ctr, int fd);
int	ft_putunbr_printf(unsigned int n, size_t *ctr, int fd);
int	ft_tohex_printf(unsigned long n, char *format, size_t *ctr, int fd);

#endif
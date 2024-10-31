/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:54:52 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/25 08:54:52 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(va_list args, char *format, size_t *ctr, int fd)
{
	int	write_error;

	if (*format == 'c')
		write_error = ft_putchar_printf(va_arg(args, int), ctr, fd);
	else if (*format == 'i' || *format == 'd')
		write_error = ft_putnbr_printf(va_arg(args, int), ctr, fd);
	else if (*format == '%')
		write_error = ft_putchar_printf('%', ctr, fd);
	else if (*format == 's')
		write_error = ft_putstr_printf(va_arg(args, char *), ctr, fd);
	else if (*format == 'u')
		write_error = ft_putunbr_printf(va_arg(args, unsigned long), ctr, fd);
	else if (*format == 'x' || *format == 'X')
		write_error = ft_tohex_printf((unsigned long)va_arg(args, unsigned int),
				format, ctr, fd);
	else if (*format == 'p')
	{
		write_error = ft_putchar_printf('0', ctr, fd);
		write_error = ft_putchar_printf('x', ctr, fd);
		write_error = ft_tohex_printf((unsigned long)(unsigned long)va_arg
				(args, void *), format, ctr, fd);
	}
	else
		write_error = -1;
	return (write_error);
}

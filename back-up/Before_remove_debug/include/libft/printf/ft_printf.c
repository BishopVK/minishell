/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:17:43 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/06 17:29:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	counter;
	int		write_error;

	if (!format)
		return (0);
	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			write_error = ft_conversions(args, (char *)format, &counter, 1);
		}
		else
			write_error = ft_putchar_printf(*format, &counter, 1);
		if (write_error < 0)
			return (-1);
		format++;
	}
	va_end(args);
	return (counter);
}

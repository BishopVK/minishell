/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:07:06 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/06 17:07:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c, size_t *ctr, int fd)
{
	int	write_error;

	write_error = write(fd, &c, 1);
	if (write_error < 0)
		return (write_error);
	(*ctr)++;
	return (write_error);
}

int	ft_putstr_printf(char *str, size_t *ctr, int fd)
{
	char	*null;
	int		write_error;

	null = "(null)";
	if (!str)
		str = null;
	while (*str)
	{
		write_error = ft_putchar_printf(*str, ctr, fd);
		if (write_error < 0)
			return (write_error);
		str++;
	}
	return (write_error);
}

int	ft_putnbr_printf(int n, size_t *ctr, int fd)
{
	int	write_error;

	if (n == -2147483648)
	{
		ft_putnbr_printf((n / 10), ctr, fd);
		write_error = ft_putchar_printf('8', ctr, fd);
	}
	else if (n < 0)
	{
		write_error = ft_putchar_printf('-', ctr, fd);
		ft_putnbr_printf(-n, ctr, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_printf((n / 10), ctr, fd);
		write_error = ft_putchar_printf((n % 10) + '0', ctr, fd);
	}
	return (write_error);
}

int	ft_putunbr_printf(unsigned int n, size_t *ctr, int fd)
{
	int	write_error;

	if (n >= 10)
		ft_putunbr_printf((n / 10), ctr, fd);
	write_error = ft_putchar_printf(((n % 10) + '0'), ctr, fd);
	return (write_error);
}

int	ft_tohex_printf(unsigned long n, char *format, size_t *ctr, int fd)
{
	int	write_error;

	if (n == 0)
		write_error = ft_putchar_printf('0', ctr, fd);
	else
	{
		if (n >= 16)
			ft_tohex_printf((n / 16), format, ctr, fd);
		if ((n % 16) < 10)
			write_error = ft_putchar_printf((n % 16) + '0', ctr, fd);
		else
		{
			if (*format == 'X')
				write_error = ft_putchar_printf((n % 16) - 10 + 'A', ctr, fd);
			else
				write_error = ft_putchar_printf((n % 16) - 10 + 'a', ctr, fd);
		}
	}
	return (write_error);
}

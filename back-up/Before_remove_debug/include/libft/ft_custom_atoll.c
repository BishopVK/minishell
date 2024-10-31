/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_atoll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:21:54 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/25 20:21:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long long int	calculate_number(const char *nptr, int sign)
{
	long long int	result;
	int				digit;
	long long int	next_result;

	result = 0;
	while (*nptr != '\0')
	{
		if (is_valid_digit(*nptr))
		{
			digit = *nptr - '0';
			next_result = result * 10 + digit;
			if ((next_result - digit) / 10 != result)
			{
				if (sign == 1)
					return (LLONG_MAX);
				else
					return (LLONG_MIN);
			}
			result = next_result;
		}
		else
			break ;
		nptr++;
	}
	return (result * sign);
}

long long int	ft_custom_atoll(const char *nptr)
{
	int	sign;

	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	return (calculate_number(nptr, sign));
}

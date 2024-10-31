/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:55:18 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/12 19:27:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Convierte una cadena de caracteres que representa
//un número en un entero (int).
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;

	sign = 1;
	while (*nptr && (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r')))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (nb * sign);
}

/*int	main(void)
{
	int	resultado;

	resultado = ft_atoi("   -21474ab83645");
	printf("Resultado = %d\n", resultado);
	return (0);
}*/

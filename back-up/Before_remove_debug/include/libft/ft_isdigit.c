/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:15 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 13:48:32 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Verifica si un carácter es un dígito numérico.
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = 'e';
	if (ft_isdigit(c) == 1)
		printf("'%c' es un dígito numérico\n", c);
	else
		printf("'%c' no es un dígito numérico\n", c);
	return (0);
} */
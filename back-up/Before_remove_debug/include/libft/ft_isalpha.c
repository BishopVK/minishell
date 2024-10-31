/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:51 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/21 16:48:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Verifica si un carácter es una letra alfabética.
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = 'e';
	if (ft_isalpha(c) == 1)
		printf("'%c' es un caracter alfabético\n", c);
	else
		printf("'%c' no es un caracter alfabético\n", c);
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:06 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 13:47:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Verifica si un valor entero representa un
//carácter ASCII válido (entre 0 y 127).
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = 'e';
	if (ft_isascii(c) == 1)
		printf("'%c' es un caracter ASCII\n", c);
	else
		printf("'%c' no es un caracter ASCII\n", c);
	return (0);
} */
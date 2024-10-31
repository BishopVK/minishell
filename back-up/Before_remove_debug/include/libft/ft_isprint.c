/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:22 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:33:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Verifica si un carácter es imprimible (visible) y pertenece
//al conjunto de caracteres imprimibles de ASCII.
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*int	main(void)
{
	char	c;
	int		num;

	c = 31;
	num = ft_isprint(c);
	if (num == 1)
		printf("El caracter introducido SI es imprimible\n");
	else
		printf("El caracter introducido NO es imprimible\n");
	return (0);
}*/

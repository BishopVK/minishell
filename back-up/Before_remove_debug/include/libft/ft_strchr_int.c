/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:48 by danjimen          #+#    #+#             */
/*   Updated: 2024/08/17 18:01:43 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la primera aparición de un carácter en una cadena.
int	ft_strchr_int(const char *s, int c)
{
	int	pos;

	pos = 0;
	c = (unsigned char)c;
	while (*s)
	{
		if (*s == c)
			return (pos);
		s++;
		pos++;
	}
	return (-1);
}

/* int	main(void)
{
	char	str[] = "En un lugar de la mancha";
	char	character = 'E';
	int	pos = ft_strchr_int(str, character);

	printf("Cadena: %s\n", str);
	if (pos != -1)
		printf("Se encontró el caracter '%c' en la posición %i\n",
			character, pos);
	else
		printf("No se encontró el caracter '%c' en la cadena\n", character);
	return (0);
} */

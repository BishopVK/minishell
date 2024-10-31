/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:06:54 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:39:21 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la última aparición de un carácter en una cadena.
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	s += len;
	c = (unsigned char)c;
	while (len >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		len--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "En un lugar de la mancha";
	char	character = 'N';
	char	*pos = ft_strrchr(str, character);

	printf("Cadena: %s\n", str);
	if (pos != NULL)
		printf("Se encontró el caracter '%c' en la posición %ld\n",
			character, pos - str);
	else
		printf("No se encontró el caracter '%c' en la cadena\n", character);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:48 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/20 12:57:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la primera aparición de un carácter en una cadena.
char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "En un lugar de la mancha";
	char	character = 'N';
	char	*pos = ft_strchr(str, character);

	printf("Cadena: %s\n", str);
	if (pos != NULL)
		printf("Se encontró el caracter '%c' en la posición %ld\n",
			character, pos - str);
	else
		printf("No se encontró el caracter '%c' en la cadena\n", character);
	return (0);
}*/

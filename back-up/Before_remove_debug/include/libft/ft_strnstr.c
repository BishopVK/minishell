/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:06:44 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/17 10:18:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la primera aparición de una subcadena en una cadena,
//hasta un número máximo de caracteres.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (needle[j] != '\0' && haystack[k] == needle[j] && k < len)
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	cadena[] = "Hola, Mundo!!";
	char	subcadena[] = "undo";
	char	*result;

	result = ft_strnstr(cadena, subcadena, 13);
	if (result != NULL)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("Subcadena no encontrada\n");
	}
	return (0);
}*/

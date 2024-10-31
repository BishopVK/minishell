/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:56:28 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/24 14:56:28 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;
	int	k;

	if (*needle == '\0')
		return (haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (needle[j] != '\0' && haystack[k] == needle[j])
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return (&haystack[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	cadena[] = "Hola, Mundo!!";
	char	subcadena[] = "";

	printf("%s", ft_strstr(cadena, subcadena));
	return (0);
}*/
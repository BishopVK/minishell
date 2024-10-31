/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:08:41 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/18 17:08:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char			*dest_start;
	unsigned int	i;

	dest_start = dest;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest_start);
}

/*int	main(void)
{
	char	src[] = "Hola mundo!";
	char	dest[20];

	ft_strcpy(dest, src);
	printf("Cadena copiada: %s\n", dest);
	return (0);
}*/
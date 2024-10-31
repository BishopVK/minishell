/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:55:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:35:31 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Obsoleto. Es similar a memset pero se usa para
//establecer en cero un bloque de memoria.
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}

/*int	main(void)
{
	char	str[] = "En un lugar de la mancha";

	printf("Antes: %s\n", str);
	ft_bzero(str, 10);
	printf("Después: %s\n", str);
	return (0);
}*/

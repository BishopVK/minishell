/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:23 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:35:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Rellena un bloque de memoria con un valor específico.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (b);
}

/*int	main(void)
{
	char str[] = "Replicando la función memset";

	printf("Inicial: %s\n", str);
	ft_memset(str, '$', 4);
	printf("Después: %s\n", str);
	return (0);
}*/

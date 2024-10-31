/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:05 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:36:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copia un bloque de memoria desde una ubicación
//de origen a una ubicación de destino.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	char	dst[50];
	char	src[] = "En un lugar de la mancha";

	printf("src: %s\n", src);
	ft_memcpy(dst, src, 25);
	printf("dest después de la copia: %s\n", dst);
	return (0);
}*/

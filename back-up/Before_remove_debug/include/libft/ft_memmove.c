/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:16 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:36:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copia un bloque de memoria desde una ubicación de origen
//a una ubicación de destino, manejando superposiciones de memoria.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (dst_tmp < src_tmp || dst_tmp >= (src_tmp + len))
	{
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		dst_tmp += len - 1;
		src_tmp += len - 1;
		while (len--)
			*dst_tmp-- = *src_tmp--;
	}
	return (dst);
}

/*int	main(void)
{
	char	dst[50];
	char	src[] = "En un lugar de la mancha";

	printf("src: %s\n", src);
	ft_memmove(dst, src, 22);
	printf("dest después de la copia: %s\n", dst);
	return (0);
}*/

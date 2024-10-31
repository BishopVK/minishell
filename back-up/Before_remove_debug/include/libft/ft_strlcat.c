/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:06:10 by danjimen          #+#    #+#             */
/*   Updated: 2024/08/17 21:49:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Concatena dos cadenas a un buffer con un límite máximo,
//evitando desbordamientos de buffer.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_length ;
	size_t	i;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	if (!dst && !src)
		return (0);
	if (dst == NULL || dstsize == 0)
		return (src_length);
	if (src == NULL)
		return (dst_length);
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	i = 0;
	while (src[i] != '\0' && i < dstsize - dst_length - 1)
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (src_length + dst_length);
}

/* int	main(void)
{
	char			dst[30] = "Hola ";
	char			src[] = "mundo1234567890abcdefghi";
	unsigned int	length;

	length = ft_strlcat(dst, src, 20);
	printf("%s\n", dst);
	printf("%u\n", length);
	return (0);
} */

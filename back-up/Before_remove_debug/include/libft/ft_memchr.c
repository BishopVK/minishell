/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:40:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Busca la primera aparición de un byte específico en un bloque de memoria.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uc_str;

	uc_str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (uc_str[i] == (unsigned char)c)
			return ((void *)(uc_str + i));
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char *str = "Hola, mundo!";
	char c = 'n';
	size_t num = strlen(str);

	void *result = ft_memchr(str, c, num);

	if (result != NULL) {
		printf("Byte encontrado: %c\n", *(char *)result);
	} else {
		printf("Byte no encontrado\n");
	}

	return (0);
}*/

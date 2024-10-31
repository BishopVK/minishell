/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:04:56 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:40:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Compara los primeros n bytes de dos bloques de memoria.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	uc_s1 = (const unsigned char *)s1;
	uc_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (uc_s1[i] != uc_s2[i])
			return (uc_s1[i] - uc_s2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1, "abcdef", 6);
	memcpy(str2, "dBCDEF", 6);
	ret = memcmp(str1, str2, 5);
	printf("Función original:\n");

	if (ret > 0)
		printf("str1 es mayor que str2\n");
	else if (ret < 0)
		printf("str1 es menor que str2\n");
	else
		printf("str1 es igual que str2\n");

	ret = ft_memcmp(str1, str2, 5);
	printf("Mi función:\n");

	if (ret > 0)
		printf("str1 es mayor que str2\n");
	else if (ret < 0)
		printf("str1 es menor que str2\n");
	else
		printf("str1 es igual que str2\n");
	return (0);
}*/

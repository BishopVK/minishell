/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:06:38 by danjimen          #+#    #+#             */
/*   Updated: 2024/09/07 22:00:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Compara los primeros n caracteres de dos cadenas.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	u_s1;
	unsigned char	u_s2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		u_s1 = (unsigned char)s1[i];
		u_s2 = (unsigned char)s2[i];
		if (u_s1 != u_s2)
			return (u_s1 - u_s2);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str1[] = "abcdef";
	char	str2[] = "abzdef";
	printf("Función original: %i\n", ft_strncmp(str1, str2, 3));
	printf("Función ft_strncmp: %i\n", ft_strncmp(str1, str2, 3));
}*/

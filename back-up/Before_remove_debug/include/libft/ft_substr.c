/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:07:08 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:46:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
//La substring empieza desde el índice ’start’ y tiene una longitud máx. ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (sub != NULL)
			sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (sub != NULL)
	{
		i = 0;
		while (i < len && s[start])
			sub[i++] = s[start++];
		sub[i] = '\0';
	}
	return (sub);
}

/*int	main(void)
{
	char			*str = "En un lugar de la mancha!!";
	char			*sub;
	unsigned int	start = 6;
	size_t 			len = 40;

	sub = ft_substr(str, start, len);
	if (sub == NULL)
		return (1);
 	
	printf("%s\n", sub);
 	free(sub);
}*/

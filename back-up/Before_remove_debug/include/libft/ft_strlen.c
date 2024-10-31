/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:06:24 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/20 12:59:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Calcula la longitud de una cadena de caracteres
//(sin incluir el carácter nulo).
size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

/*int	main(void)
{
	char	str[] = "HOLA Caracola";
	int		lenght;
	
	lenght = ft_strlen(str);
	printf("String: %s\n", str);
	printf("Longitud: %d\n", lenght);

	return (0);
}*/

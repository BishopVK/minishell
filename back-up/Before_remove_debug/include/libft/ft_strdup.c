/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:53 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/20 13:00:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Duplica una cadena de caracteres en una nueva ubicación de memoria,
//asignando dinámicamente espacio suficiente
//y copiando el contenido de la cadena original.
char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*start;

	if (s == NULL)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	start = dest;
	while (*s != '\0')
		*dest++ = *s++;
	*dest = '\0';
	return (start);
}

/* void ft_leaks(void)
{
	system("leaks -q a.out");
} */

/* int	main(void)
{
	//atexit(ft_leaks);
	const char	*s = "HOLA";
	char		*dst;

	dst = ft_strdup(s);

	printf("Origen %s\n", s);
	printf("Destino %s\n", dst);

	free(dst);
	system("leaks -q a.out");
	return (0);
} */

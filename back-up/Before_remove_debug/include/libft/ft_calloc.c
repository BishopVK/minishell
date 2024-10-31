/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:01:18 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/08 13:54:37 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Asigna dinámicamente un bloque de memoria para un número
//especificado de elementos, inicializando cada byte a cero.
void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
//Compilar con ft_strlcpy.c ft_strlen.c ft_memset.c
/*int	main(void)
{
	char *ptr;
	ptr = ft_calloc(10, sizeof(char));

	if (ptr == NULL)
		return (1);
 	
	ft_strlcpy(ptr, "Hola", 5);
 	
	printf("%s\n", ptr);
 	free(ptr);

	//////////
	size_t count = 5;
	size_t size = sizeof(int);
	int	*arr = (int *)ft_calloc(count, size);

	if (arr != NULL)
	{
		printf("La alocación de memoria ha ido correctamente.\n");
		free(arr);
	}
	else
		printf("La alocación de memoria ha fallado.\n");
 	return (0);
}*/

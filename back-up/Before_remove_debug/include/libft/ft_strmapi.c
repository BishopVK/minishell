/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:06:31 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/23 14:06:31 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros
//el índice de cada carácter dentro de ’s’ y el propio carácter.
//Genera una nueva string con el resultado del uso sucesivo de ’f’
/*static char	ft_toggle_case(unsigned int n, char c)
{
	(void)n;
	if (c >= 'a' && c <= 'z')
		return ((char)(c - 'a' + 'A'));
	if (c >= 'A' && c <= 'Z')
		return ((char)(c - 'A' + 'a'));
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main(void)
{
	char const	*s = "abcdefghijklmnñopqrstuvwxyz,ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
	char	*result;

	result = ft_strmapi(s, ft_toggle_case);

	if (result != NULL)
	{
		printf("Resultado: %s\n", result);
		free(result);
	}
	else
		printf("Fallo en la reserva de memoria\n");
	return (0);
}*/
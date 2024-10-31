/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:59 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/23 14:05:59 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros
//el índice de cada carácter dentro de ’s’ y la dirección del propio carácter,
//que podrá modificarse si es necesario.
/*static void	ft_toggle_case(unsigned int n, char *c)
{
	(void)n;
	if (*c >= 'a' && *c <= 'z')
		*c = (char)(*c - 'a' + 'A');
	else if (*c >= 'A' && *c <= 'Z')
		*c = (char)(*c - 'A' + 'a');
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	char	s[] = "abcdefghijklmnñopqrstuvwxyz,ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

	printf("Original: %s\n", s);
	ft_striteri(s, ft_toggle_case);
	printf("Resultado: %s\n", s);
	return (0);
}*/
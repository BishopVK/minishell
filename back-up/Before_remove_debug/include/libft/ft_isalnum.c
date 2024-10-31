/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:17 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 13:48:30 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Verifica si un carácter es alfanumérico, es decir, una letra o un dígito.
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = 'e';
	if (ft_isalnum(c) == 1)
		printf("'%c' es un carácter alfanumérico\n", c);
	else
		printf("'%c' no es un carácter alfanumérico\n", c);
	return (0);
} */

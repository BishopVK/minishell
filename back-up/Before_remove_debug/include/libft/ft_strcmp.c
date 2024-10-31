/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:29:58 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/23 13:29:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	str1[] = "abc";
	char	str2[] = "abz";
	int		cmp = ft_strcmp(str1, str2);

	printf("%i\n", cmp);
	if (cmp < 0)
		printf("%s es más pequeño que %s\n", str1, str2);
	else if (cmp > 0)
		printf("%s es más grande que %s\n", str1, str2);
	else
		printf("%s y %s son iguales\n", str1, str2);
	
	return (0);
} */
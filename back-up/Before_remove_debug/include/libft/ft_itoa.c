/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:28:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/14 15:02:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Utilizando malloc(3), genera una string que represente el valor entero
//recibido como argumento. Los números negativos tienen que gestionarse.
static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_num_to_string(int n, int len, int negative)
{
	char	*str;

	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	len = len - 1;
	str[len] = '\0';
	while (len-- > 1)
	{
		str[len] = (char)((n % 10) + 48);
		n = n / 10;
	}
	if (negative == 1)
		str[len] = '-';
	else
		str[len] = (char)((n % 10) + 48);
	return (str);
}

static char	*ft_special_nbrs(int n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "0", 2);
		return (str);
	}
	if (n == -2147483648)
	{
		str = (char *)malloc(12 * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		len;

	negative = 0;
	if (n == 0 || n == -2147483648)
	{
		str = ft_special_nbrs(n);
		return (str);
	}
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	len = (ft_num_len(n) + negative + 1);
	str = ft_num_to_string(n, len, negative);
	return (str);
}

/*int  main(void)
{
	// Test 1: Número positivo
	int num1 = 12345;
	char* str1 = ft_itoa(num1);
	printf("Test 1: %d convertido a cadena: %s\n", num1, str1);
	free(str1);

	// Test 2: Número negativo
	int num2 = -9876;
	char* str2 = ft_itoa(num2);
	printf("Test 2: %d convertido a cadena: %s\n", num2, str2);
	free(str2);

	// Test 3: Número cero
	int num3 = 0;
	char* str3 = ft_itoa(num3);
	printf("Test 3: %d convertido a cadena: %s\n", num3, str3);
	free(str3);

	// Test 4: Número grande
	int num4 = 2147483647; // Máximo valor para un int en sistemas de 32 bits
	char* str4 = ft_itoa(num4);
	printf("Test 4: %d convertido a cadena: %s\n", num4, str4);
	free(str4);

	// Test 5: Número mínimo para un int en sistemas de 32 bits
	int num5 = -2147483648; // Mínimo valor para un int en sistemas de 32 bits
	char* str5 = ft_itoa(num5);
	printf("Test 5: %d convertido a cadena: %s\n", num5, str5);
	free(str5);

	// Test 6: Número con varios ceros al principio
	int num6 = 0005000;
	char* str6 = ft_itoa(num6);
	printf("Test 6: %d convertido a cadena: %s\n", num6, str6);
	free(str6);

	// Test 7: Número con varios ceros al final
	int num7 = 120000;
	char* str7 = ft_itoa(num7);
	printf("Test 7: %d convertido a cadena: %s\n", num7, str7);
	free(str7);

	// Test 8: Número con varios ceros intermedios
	int num8 = 10203;
	char* str8 = ft_itoa(num8);
	printf("Test 8: %d convertido a cadena: %s\n", num8, str8);
	free(str8);

	return 0;
}*/

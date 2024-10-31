/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:55:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Cuenta el número de nodos de una lista.
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*int	main(void)
{
	// Crear algunos nodos de la lista para el ejemplo
	t_list	node1;
	t_list	node2;
	t_list	node3;
	int		size;

	node1.content = "Nodo 1";
	node1.next = &node2;

	node2.content = "Nodo 2";
	node2.next = &node3;

	node3.content = "Nodo 3";
	node3.next = NULL;

	// Pasa el puntero al primer nodo a ft_lstsize para contar los elementos
	size = ft_lstsize(&node1);

	// Imprime el resultado
	printf("El tamaño de la lista es: %d\n", size);
	return (0);
}*/
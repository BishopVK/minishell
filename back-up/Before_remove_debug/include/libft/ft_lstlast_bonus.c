/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:21:31 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:55:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Devuelve el último nodo de la lista.
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	// Crear algunos nodos de la lista para el ejemplo
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	*my_list;

	node1.content = "Nodo 1";
	node1.next = &node2;

	node2.content = "Nodo 2";
	node2.next = &node3;

	node3.content = "Nodo 3";
	node3.next = NULL;

	// Pasa el puntero al primer nodo a ft_lstlast
	my_list = ft_lstlast(&node1);

	// Imprime el resultado
	if (my_list != NULL)
		printf("El último nodo es: %s\n", (char *)my_list->content);
	else
		printf("La lista está vacía.\n");

	return (0);
}*/
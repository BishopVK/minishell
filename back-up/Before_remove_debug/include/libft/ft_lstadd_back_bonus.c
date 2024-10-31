/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:03:52 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:55:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Añade el nodo ’new’ al final de la lista ’lst’.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*int	main(void)
{
	// Crear algunos nodos de la lista para el ejemplo
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	*my_list;
	t_list	*new_node;

	node1.content = "Nodo 1";
	node1.next = &node2;

	node2.content = "Nodo 2";
	node2.next = &node3;

	node3.content = "Nodo 3";
	node3.next = NULL;

	// Asignar memoria para el nuevo nodo
	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->content = "NEW_NODE";
	new_node->next = NULL;

	// Pasa el puntero al primer nodo a ft_lstadd_back
	ft_lstadd_back(&my_list, new_node);

	// Imprime el resultado recorriendo la lista hasta el final
	t_list *current = my_list;
	while (current->next != NULL)
		current = current->next;

	// Imprime el resultado recorriendo la lista hasta el final
	if (my_list != NULL)
		printf("El último nodo es: %s\n", (char *)my_list->content);
	else
		printf("La lista está vacía.\n");

	// Liberar memoria asignada con malloc
	free(new_node);

	return (0);
}*/
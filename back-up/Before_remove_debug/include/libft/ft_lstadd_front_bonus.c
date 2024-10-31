/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:54:38 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:55:04 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Añade el nodo ’new’ al principio de la lista ’lst’.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else if (*lst != NULL)
		new->next = *lst;
	*lst = new;
}
/* int	main(void)
{
	// Crear un nodo y asignarle un valor
	t_list *node1 = malloc(sizeof(t_list));
	if (node1 == NULL)
	{
		fprintf(stderr, "Error de asignación de memoria.\n");
		return (1);
	}
	node1->content = (void *)42; // Convertir el entero a puntero void *
	node1->next = NULL;

	// Crear una lista con un nodo inicial
	t_list *my_list = node1;

	// Imprimir la lista antes de añadir un nuevo nodo
	printf("Lista antes de agregar un nuevo nodo:\n");
	while (my_list != NULL)
	{
		// Convertir el puntero void * a entero
		printf("%d -> ", (int)(intptr_t)my_list->content);
		my_list = my_list->next;
	}
	printf("NULL\n");

	// Crear un nuevo nodo y asignarle un valor
	t_list *new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error de asignación de memoria.\n");
		free(node1);
		return 1;
	}
	new_node->content = (void *)99; // Convertir el entero a puntero void *
	new_node->next = NULL;

	// Agregar el nuevo nodo al principio de la lista
	ft_lstadd_front(&my_list, new_node);

	// Imprimir la lista después de agregar el nuevo nodo
	printf("\nLista después de agregar un nuevo nodo:\n");
	while (my_list != NULL)
	{
		// Convertir el puntero void * a entero
		printf("%d -> ", (int)(intptr_t)my_list->content);
		my_list = my_list->next;
	}
	printf("NULL\n");

	// Liberar la memoria asignada para los nodos
	free(node1);
	free(new_node);

	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:30:59 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:54:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ se
//inicializa con el contenido del parámetro ’content’.
//La variable ’next’, con NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*int	main(void)
{
	// Prueba 1: Crear un nodo con contenido de tipo entero
	int *data = (int *)malloc(sizeof(int));
	*data = 42;
	t_list *node1 = ft_lstnew(data);

	// Prueba 2: Crear un nodo con contenido de tipo entero
	int data2 = 42;
	t_list *node2 = ft_lstnew(&data2);

	// Prueba 3: Crear un nodo con contenido de tipo cadena de caracteres
	char *str = "Hello, World!";
	t_list *node3 = ft_lstnew(str);

	// Imprimir los contenidos de los nodos
	printf("Node 1 content: %d\n", *(int *)(node1->content));
	printf("Node 2 content: %d\n", *(int *)(node2->content));
	printf("Node 3 content: %s\n", (char *)(node3->content));

	// Liberar la memoria asignada
	free(data);
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/
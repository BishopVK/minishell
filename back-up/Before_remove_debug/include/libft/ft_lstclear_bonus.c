/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:46:03 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:57:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo,
//utilizando la función ’del’ y free(3).
//Al final, el puntero a la lista debe ser NULL.
/*static void	ft_del_node_content(void *content)
{
	if (content != NULL)
		free(content);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (lst != NULL && del != NULL)
	{
		while (current != NULL)
		{
			next = current->next;
			del(current->content);
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}

/*int	main(void)
{
	// Crear algunos nodos de la lista para el ejemplo
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		size;

	// Crear manualmente los nodos
	node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = ft_strdup("NODO 3");
	node3->next = NULL;

	node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = ft_strdup("NODO 2");
	node2->next = node3;

	node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = ft_strdup("NODO 1");
	node1->next = node2;

	// Obtener cuandos nodos existen
	size = ft_lstsize(node1);

	// Imprimir el nº de nodos
	printf("El tamaño de la lista es: %d\n", size);

	// Pasa el puntero al primer nodo a ft_lstclear
	ft_lstclear(&node1, ft_del_node_content);

	// Establecer manualmente node2 y node3 en NULL
	node2 = NULL;
	node3 = NULL;

	// Comprobamos si los nodos son nulos
	printf("Valor de node1: %p\n", (void *)node1);
	printf("Valor de node2: %p\n", (void *)node2);
	printf("Valor de node3: %p\n", (void *)node3);

	// Imprimir mensaje indicando que la lista está vacía
	if (node1 == NULL && node2 == NULL && node3 == NULL)
		printf("La lista ahora está vacía.\n");

	return (0);
}*/
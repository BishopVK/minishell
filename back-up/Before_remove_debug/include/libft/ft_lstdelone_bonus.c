/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:52:09 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:56:26 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Toma como parámetro un nodo ’lst’ y libera la memoria del contenido
//utilizando la función ’del’ dada como parámetro, además
//de liberar el nodo. La memoria de ’next’ no debe liberarse.
/* static void	ft_del_node_content(void *content)
{
	if (content != NULL)
		free(content);
} */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
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

	// Llamamos a la función para eliminar el último nodo
	ft_lstdelone(my_list, ft_del_node_content);

	// Volvemos a pasa el puntero al primer nodo a ft_lstlast
	my_list = ft_lstlast(&node1);

	// Imprime el resultado
	if (my_list != NULL)
		printf("El último nodo ahora es: %s\n", (char *)my_list->content);
	else
		printf("La lista está vacía.\n");

	return (0);
}*/
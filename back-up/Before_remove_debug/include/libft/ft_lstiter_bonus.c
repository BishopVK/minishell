/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:52:35 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:57:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada nodo.
/* static void	ft_strlowcase(void *content)
{
	if (content != NULL)
	{
		while (*((char *)content))
		{
			if (*((char *)content) >= 'A' && *((char *)content) <= 'Z')
				*((char *)content) = *((char *)content) + 32;
			content = (char *)content + 1;
		}
	}
} */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
//cc -Wall -Wextra -Werror ft_lstiter_bonus.c ft_strdup.c ft_strlen.c 
/* int	main(void)
{
	// Crear algunos nodos de la lista para el ejemplo
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list *my_list;

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

	// Imprimir los contenidos de los nodos
	printf("Antes de ft_lstiter:\n");
	my_list = node1;
	while (my_list != NULL)
	{
		printf("Nodo: %p. Content: %s\n", my_list, (char *)(my_list->content));
		my_list = my_list->next;
	}

	// Pasa el puntero al primer nodo a ft_lstiter
	ft_lstiter(node1, ft_strlowcase);

	// Imprimir nuevamente los contenidos de los nodos
	printf("Después de ft_lstiter:\n");
	my_list = node1;
	while (my_list != NULL)
	{
		printf("Nodo: %p. Content: %s\n", my_list, (char *)(my_list->content));
		my_list = my_list->next;
	}

	// Después de imprimir los contenidos de los nodos, liberar los nodos
	free(node1->content);
	free(node1);
	free(node2->content);
	free(node2);
	free(node3->content);
	free(node3);

	return (0);
} */
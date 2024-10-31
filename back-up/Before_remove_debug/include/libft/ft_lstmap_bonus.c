/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:00:41 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/14 12:50:28 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo.
//Crea una lista resultante de la aplicación correcta y sucesiva de la
//función ’f’ sobre cada nodo. La función ’del’ se utiliza para
//eliminar el contenido de un nodo, si hace falta.
/* static void	ft_del_node_content(void *content)
{
	if (content != NULL)
		free(content);
} */

/* static void	*ft_strlowcase(void *content)
{
	char	*str;
	int		size;

	if (content != NULL)
	{
		str = (char *)content;
		size = ft_strlen(str);
		while (*str)
		{
			if (*str >= 'A' && *str <= 'Z')
				*str = *str + 32;
			str++;
		}
		return (str - size);
	}
	return (NULL);
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*my_new_list;
	t_list	*new_node;
	t_list	*buffer;

	my_new_list = NULL;
	if (lst != NULL && f != NULL && del != NULL)
	{
		while (lst != NULL)
		{
			buffer = (f(lst->content));
			new_node = ft_lstnew(buffer);
			if (new_node == NULL)
			{
				del(buffer);
				ft_lstclear(&my_new_list, del);
				return (NULL);
			}
			ft_lstadd_back(&my_new_list, new_node);
			lst = lst->next;
		}
	}
	else
		return (NULL);
	return (my_new_list);
}
/* int	main(void)
{
	// Crear algunos nodos de la lista para el ejemplo
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*my_list;
	t_list	*my_new_list;

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
	printf("Antes de ft_lstmap:\n");
	my_list = node1;
	while (my_list != NULL)
	{
		printf("Nodo: %p. Content: %s\n", my_list, (char *)(my_list->content));
		my_list = my_list->next;
	}

	// Pasa el puntero al primer nodo a ft_lstmap
	my_new_list = ft_lstmap(node1, ft_strlowcase, ft_del_node_content);

	// Imprimir los contenidos de los nodos de la nueva lista
	printf("Después de ft_lstmap:\n");
	while (my_new_list != NULL)
	{
		printf("Nd: %p. Cnt: %s\n", my_new_list, (char *)(my_new_list->content));
		my_new_list = my_new_list->next;
	}

	//¿?
	// Después de imprimir los contenidos de los nodos, liberar la nueva lista
	//free(node1->content);
	//free(node1);
	//free(node2->content);
	//free(node2);
	//free(node3->content);
	//free(node3);
	ft_lstclear(&my_list, ft_del_node_content);
	ft_lstclear(&my_new_list, ft_del_node_content);

	return (0);
} */

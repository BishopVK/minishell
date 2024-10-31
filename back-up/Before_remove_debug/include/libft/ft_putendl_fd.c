/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:35:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/29 09:53:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//Envía la string ’s’ al file descriptor dado, seguido de un salto de línea.
void	ft_putendl_fd(char *s, int fd)
{
	char	newline;

	newline = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &newline, 1);
}

/*int	main(void)
{
	int		fd;
	char	*str = "Hola Mundo!!";

	// Abre o crea un archivo llamado "ejemplo.txt"
	// en modo de escritura (O_WRONLY)
	// y con la bandera O_CREAT que crea el archivo si no existe.
	fd = open("ejemplo.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (EXIT_FAILURE);
	}

	// Llama a la función para escribir el carácter en el archivo
	ft_putendl_fd(str, fd);

	// Cierra el archivo
	if (close(fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (EXIT_FAILURE);
	}

	// Mostrar el contenido del archivo
	system("cat ejemplo.txt");

	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:05:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/20 12:30:03 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//Envía el carácter ’c’ al file descriptor especificado.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main(void)
{
	int		fd;
	char	caracter;

	// Abre o crea un archivo llamado "ejemplo.txt"
	// en modo de escritura (O_WRONLY)
	// y con la bandera O_CREAT que crea el archivo si no existe.
	fd = open("ejemplo.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (EXIT_FAILURE);
	}

	// Carácter que queremos escribir en el archivo
	caracter = 'c';

	// Llama a la función para escribir el carácter en el archivo
	ft_putchar_fd(caracter, fd);

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
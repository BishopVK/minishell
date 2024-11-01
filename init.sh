#!/bin/bash

# Actualizar el repositorio
git pull

# Instalar dependencias si es necesario
sudo apt-get update
sudo apt-get install -y build-essential libreadline-dev

# Compilar el proyecto
make

# Ejecutar minishell
./minishell

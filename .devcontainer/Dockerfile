FROM ubuntu:20.04

# Configurar el contenedor para evitar preguntas interactivas
ENV DEBIAN_FRONTEND=noninteractive

# Instalar dependencias
RUN apt-get update && apt-get install -y \
    build-essential \
    libreadline-dev \
    && rm -rf /var/lib/apt/lists/*
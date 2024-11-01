# Usa una imagen base adecuada
FROM ubuntu:20.04

# Configurar el contenedor para evitar preguntas interactivas
ENV DEBIAN_FRONTEND=noninteractive

# Actualizar el sistema e instalar dependencias
RUN apt-get update && apt-get install -y \
    build-essential \
    libreadline-dev \
    && rm -rf /var/lib/apt/lists/*

# Establecer el directorio de trabajo
WORKDIR /workspace

# Copiar el código fuente al contenedor
COPY . .

# Compilar el proyecto
RUN make
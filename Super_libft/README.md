*Este proyecto ha sido creado como parte del currículo de 42 por fejimene.*

# Libft

## Descripción
**Libft** es el primer proyecto del currículo de la escuela 42. El objetivo de este proyecto es reescribir desde cero varias funciones estándar de la biblioteca de C (`libc`), así como otras funciones de utilidad general y manipulación de listas enlazadas. 

En los futuros proyectos de 42 esta biblioteca personalizada (`libft.a`) será la herramienta base que se utilizará a lo largo de todo el cursus. Este proyecto permite comprender a bajo nivel la gestión dinámica de memoria, el uso de punteros y la estructura de las listas enlazadas.

## Características
El proyecto se divide en tres partes principales:

1. **Funciones de la Libc:** Implementación de funciones clásicas como `ft_strlen`, `ft_strchr`, `ft_strncmp`, `ft_atoi`, `ft_calloc`, `ft_strdup`, y funciones de memoria como `ft_memset`, `ft_bzero`, `ft_memcpy`, entre otras.
2. **Funciones adicionales:** Herramientas útiles para el manejo de strings y números, tales como `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi` y funciones de escritura en file descriptors (`ft_putchar_fd`, etc.).
3. **Listas enlazadas:** Estructura y funciones para el manejo de listas simples (creación de nodos, adición al principio/final, iteración, mapeo y liberación de memoria).

## Instrucciones

### Compilación e Instalación
El proyecto incluye un `Makefile` que compila los archivos fuente y genera una biblioteca estática llamada `libft.a`.

Para compilar la biblioteca:
```bash
make
```

Otros comandos útiles del Makefile:
* `make clean`: Elimina los archivos objeto (`.o`).
* `make fclean`: Ejecuta `clean` y además elimina el archivo `libft.a`.
* `make re`: Ejecuta `fclean` y vuelve a compilar todo (`make`).

## Recursos

### Referencias técnicas
* **Manuales de Linux/Unix (`man`):** Uso de las páginas del manual para comprender el comportamiento esperado, los valores de retorno y la gestión de punteros nulos de las funciones originales.
* **Valgrind:** Herramienta fundamental utilizada para la detección de *memory leaks* (fugas de memoria) y errores de segmentación.

### Uso de Inteligencia Artificial
Durante el desarrollo de este proyecto, se ha utilizado un asistente de IA estrictamente como herramienta de apoyo para las siguientes tareas:
* **Debugging y gestión de memoria:** Análisis de error de Valgrind para comprender la raíz y fugas de memoria en funciones complejas de asignación dinámica.
* **Protección contra Segmentation Faults:** Ayuda para entender cómo usar de forma segura los dobles punteros (`**lst`) y proteger las funciones de listas enlazadas para que no fallen al recibir valores nulos `NULL`.
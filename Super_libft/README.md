# Super Libft

*Este proyecto ha sido creado como parte del currículo de 42 por fejimene.*

> **Nota importante:** Esta no es la `libft` estándar del primer proyecto de 42. `Super_libft` es una librería estática unificada y expandida, diseñada para ser el "motor" principal de todos mis futuros proyectos en la escuela.

## ¿Qué es la Super Libft?

En la escuela 42, no se nos permite usar algunas funciones estándar de C sin haberlas reprogramado nosotros mismos. 

Para no tener que reescribir código constantemente, he agrupado mis principales proyectos de nivel 0 y 1 en esta única súper-librería. Al compilarla, genera un único archivo `super_libft.a` que contiene todas estas herramientas.

### Proyectos integrados:
* **Libft base:** Todas las funciones de la Libc (`ft_strlen`, `ft_atoi`, `ft_split`, etc.) y utilidades de manipulación de strings y memoria.
* **Libft Bonus:** Gestión completa de listas enlazadas (`ft_lstnew`, `ft_lstadd_back`, `ft_lstclear`, etc.).
* **ft_printf:** Mi propia versión de la función `printf` de C, capaz de manejar múltiples conversiones (`%s`, `%d`, `%x`, `%p`, etc.).
* **get_next_line:** Función optimizada para leer archivos línea por línea, incluyendo soporte para *bonus* (múltiples File Descriptors simultáneos).

---

## Cómo integrarla en otros proyectos

Esta librería está pensada para vivir como un submódulo o subcarpeta dentro de proyectos más grandes. 

### 1. Estructura de carpetas recomendada
Coloca toda esta carpeta dentro de la raíz de tu nuevo proyecto:
```text
mi_nuevo_proyecto/
├── Makefile
├── Tu_programa.c
└── Super_libft/
    ├── Makefile
    ├── super_libft.h
    └── (archivos .c)
```

### 2. Configuración en tu código C
Al estar todo unificado, solo necesitas incluir una cabecera en tus archivos `.c` para tener acceso a `printf`, `get_next_line` y todas las utilidades de la libft:
```c
#include "super_libft.h"
```

### 3. Configuración en tu Makefile principal
Para que tu proyecto reaccione a la librería, asegúrate de que tu `Makefile` principal tenga la bandera `-I` para las cabeceras, y que llame al Makefile de `Super_libft` antes de compilar el binario:

```makefile
# Variables de la librería
LIB_DIR = Super_libft
LIB_A = $(LIB_DIR)/super_libft.a
INCLUDES = -I. -I./Super_libft

# Regla para compilar la librería automáticamente
$(LIB_A):
	$(MAKE) -C $(LIB_DIR)

# Regla para tu programa principal
tu_programa: $(OBJ) $(LIB_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_A) $(INCLUDES) -o tu_programa

# Regla para compilar tus .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
```

---

## Comandos del Makefile de Super_libft

Si quieres probar o compilar la librería de forma independiente, puedes usar los comandos estándar dentro de su carpeta:

| Comando | Descripción |
| :--- | :--- |
| `make` | Compila todos los archivos `.c` y genera el archivo `super_libft.a`. |
| `make clean` | Elimina todos los archivos objeto (`.o`) generados durante la compilación. |
| `make fclean` | Ejecuta `clean` y además elimina el archivo `super_libft.a`. |
| `make re` | Ejecuta `fclean` y luego `make`, recompilando todo desde cero. |

---
*Proyecto creado para el cursus de 42.*
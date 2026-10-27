*Este proyecto ha sido creado como parte del currículo de 42 por jmunoz-j, fejimene.*

# Push_swap

## Descripción
Push_swap es un proyecto de algoritmia del Common Core de 42. El objetivo es ordenar una pila de números enteros (`stack a`) utilizando una pila auxiliar (`stack b`) y un conjunto muy limitado de operaciones permitidas. El verdadero reto del proyecto radica en la optimización: no solo hay que ordenar los datos, sino hacerlo utilizando la menor cantidad de movimientos posibles, evaluando diferentes niveles de complejidad algorítmica y calculando el índice de desorden inicial para aplicar la estrategia óptima en cada caso.

## Instrucciones de compilación y ejecución
El proyecto incluye un `Makefile` estándar.

**Para compilar el proyecto:**
```bash
make
```

**Para ejecutar el programa:**
Pasa una lista de números enteros como argumentos. El programa devolverá la lista de operaciones necesarias para ordenarlos.
```bash
./push_swap 4 67 3 87 23
```

**Flags disponibles (Selector de estrategias):**
-   `--simple`: Fuerza el algoritmo de complejidad $O(n^2)$.
-   `--medium`: Fuerza el algoritmo de complejidad $O(n\sqrt{n})$.
-   `--complex`: Fuerza el algoritmo de complejidad $O(n \log n)$.
-   `--adaptive`: (Por defecto) Selecciona la estrategia automáticamente basándose en el índice de desorden.
-   `--bench`: Muestra las estadísticas de la ordenación por la salida de error estándar (`stderr`).

## Bonus: Evaluador (Checker)
El proyecto incluye un programa adicional llamado `checker`, desarrollado como parte de la parte *bonus* del *subject*. Su función es validar si una secuencia de operaciones ordena correctamente la pila proporcionada.

**Para compilar el bonus:**
```bash
make bonus
```

**Para ejecutar el checker de forma manual:**
```bash
./checker 4 67 3 87 23
```
*(El programa quedará a la espera de instrucciones por la entrada estándar. Puedes escribir comandos como `sa`, `pb`, `ra` pulsando Enter tras cada uno. Para finalizar la entrada, pulsa `Ctrl+D`).*

**Para evaluar automáticamente push_swap (usando tuberías/pipes):**
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

**Resultados de la evaluación:**
El `checker` ejecuta los movimientos en absoluto silencio. Al finalizar la lectura, comprueba el estado de las pilas e imprime por la salida estándar:
-   `OK`: Si el *stack a* está perfectamente ordenado de menor a mayor y el *stack b* está vacío.
-   `KO`: Si las pilas no están ordenadas correctamente al finalizar.
-   `Error`: Si se introduce una instrucción inválida, o si los argumentos iniciales contienen errores (no numéricos, duplicados, fuera del límite de `int`). Este mensaje se envía siempre a la salida de error (`stderr`).

## Justificación de Algoritmos
Para cumplir con los requisitos de complejidad, hemos implementado las siguientes estrategias:

### 1. Algoritmo Simple - $O(n^2)$
**Implementado en:** `ft_simple_sort.c` / `ft_sort_small.c`
Consiste en buscar de forma secuencial el número mínimo en el `stack a`, rotarlo hasta la cima y pasarlo al `stack b`. Al finalizar, se devuelven todos a `a`. Este bucle anidado (buscar el menor iterando sobre los elementos restantes) representa la complejidad clásica $O(n^2)$, ideal para casos de muy pocos números.

### 2. Algoritmo Intermedio - $O(n\sqrt{n})$
**Implementado en:** `ft_medium_sort.c`
**Justificación:** Implementamos un algoritmo basado en *Chunks* (tramos). La lista se indexa y se envían los números a la pila B divididos en pequeños rangos o porciones. Esto reduce significativamente la cantidad de búsquedas en comparación con el algoritmo simple, acercando el rendimiento matemático a la complejidad de $O(n\sqrt{n})$.

### 3. Algoritmo Complejo - $O(n \log n)$
**Implementado en:** `ft_complex_sort.c`
**Algoritmo:** Radix Sort (Base 2)
**Justificación:** Para el requisito de mayor complejidad algorítmica, implementamos un Radix Sort en base 2. Antes de comenzar, se indexa la pila (de $0$ a $N-1$) para normalizar los valores y evitar problemas con números negativos. El algoritmo evalúa la representación binaria de cada índice bit a bit. Si el bit evaluado es $0$, el nodo se empuja a la pila B (`pb`); si es $1$, se rota en la pila A (`ra`). Una vez procesados todos los nodos para un bit específico, se devuelve todo de B a A. Este enfoque no comparativo y altamente predecible garantiza una complejidad de tiempo que se ajusta al modelo $O(n \log n)$ requerido.

### 4. Algoritmo Adaptativo (Thresholds)
**Implementado en:** `main.c` (función `ft_adaptive`)
**Justificación:** El programa calcula el índice de desorden evaluando cuántos pares de números están en la posición incorrecta. 
-   **Desorden < 0.2 (Bajo):** Deriva a algoritmos simples ($O(n^2)$) ya que la pila está casi ordenada y requiere pocas correcciones.
-   **0.2 <= Desorden < 0.5 (Medio):** Utiliza el algoritmo de Chunks ($O(n\sqrt{n})$).
-   **Desorden >= 0.5 (Alto):** Activa el Radix Sort ($O(n \log n)$) para garantizar estabilidad y rendimiento frente al caos absoluto.

## Contribuciones del Equipo
Este proyecto ha sido desarrollado colaborativamente. **Aunque se ha hecho un reparto de tareas inicial, posteriormente se ha ido depurando el funcionamiento de cada una de las funciones de manera conjunta.** A continuación se detalla el reparto de tareas:

-   **jmunoz-j:**
    *   Gestión de movimientos básicos y optimización de rotaciones: `ft_swap.c`, `ft_push.c`.
    *   Algoritmos para listas pequeñas y simples: `ft_sort_small.c`, `ft_simple_sort.c`.
    *   Validación de entrada y parseo robusto (blindaje contra errores): `ft_push_input_check.c`.
    *   Gestión de memoria, inicialización y limpieza de la lista enlazada: `ft_init_free.c`, `ft_dlstclear.c`.
-   **fejimene:**
    *   Lógicas de rotación y rotación inversa: `ft_rotate.c` `ft_reverse_rotate.c`.
    *   Algoritmo intermedio (Chunk Sort): `ft_medium_sort.c`.
    *   Algoritmo complejo (Radix Sort): `ft_complex_sort.c`.
    *   Cálculo del índice matemático de desorden: `ft_disorder.c`.
    *   Implementación y lógica del sistema de métricas (Benchmark): `ft_bench.c`.
-   **Desarrollo Conjunto (jmunoz-j & fejimene):**
    *   Arquitectura principal, flujos adaptativos y selectores de estrategia: `main.c`.
    *   Programa evaluador y lectura dinámica (Bonus): `checker.c`.
    *   Población de nodos desde el parser: `ft_fill_nodes.c`.
    *   Configuración de compilación y reglas del proyecto: `Makefile`.
    *   Definición de estructuras, prototipos y macros principales: `push_swap.h`, `checker.h`.

## Recursos e Inteligencia Artificial

-   **Recursos Clásicos:** Consultas a artículos sobre complejidad algorítmica (Notación Big-O) y comparativas de algoritmos de ordenación en estructuras de datos lineales.

-   **Uso de Inteligencia Artificial:** Se utilizó asistencia de IA estrictamente como herramienta de tutoría, consulta y depuración. No se generó código base a ciegas, sino que se aplicó en las siguientes áreas clave:

    *   **Comprensión algorítmica:** Para entender y asimilar la lógica matemática detrás de los algoritmos complejos (como *Radix Sort* y el algoritmo por tramos o *Chunk Sort*), así como su impacto directo en la complejidad temporal ($O(n \log n)$, $O(n\sqrt{n})$).

    *   **Gestión de memoria y seguridad:** Para rastrear visualmente el flujo de memoria, prevenir punteros colgantes (*dangling pointers*) y asegurar la resolución de fugas de memoria (*leaks*) en casos límite, como fallos en el parseo o errores de lectura.
    
    *   **Documentación:** Asistencia en la estructuración y redacción de este archivo `README.md` para asegurar que la presentación de nuestro trabajo cumple con todos los requisitos del *subject* de manera profesional y clara.
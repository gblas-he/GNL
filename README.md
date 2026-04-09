*Este proyecto ha sido creado como
parte del currículo de 42 por gblas-he.*

# Get Next Line
## Descripción
El objetivo de este proyecto es programar una función que devuelva una línea leída desde un descriptor de archivo (file descriptor). `get_next_line` permite procesar archivos de texto de manera secuencial, devolviendo una línea completa en cada llamada hasta alcanzar el final del archivo o un error.

Este reto es fundamental porque introduce el uso de **variables estáticas** en C y requiere una gestión de memoria dinámica impecable para evitar fugas (memory leaks).

### Librería
El proyecto incluye funciones auxiliares:

- `ft_strlen`: calcula la longitud de una cadena
- `ft_strchr`: busca un carácter en una cadena
- `ft_strjoin`: concatena dos cadenas en una nueva
- `ft_calloc`: reserva memoria e inicializa a 0

## Instrucciones de Uso
### Compilación
El proyecto debe poder compilarse con y sin el indicador `-D BUFFER_SIZE=n`, el cual define el tamaño del buffer para las lecturas de `read()`.

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

## Recursos
- [Read](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/ )
- [Variables estáticas](https://www.geeksforgeeks.org/c/static-variables-in-c/ )
- [GNL](https://medium.com/@lannur-s/42-get-next-line-guide-string-approach-chapter-4-all-about-the-buffer-5a8ef81a6551)
- [Malloc y free](https://www.geeksforgeeks.org/c/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)

### Uso de IA
Se ha utilizado ChatGPT como apoyo para:
- Comprender el funcionamiento de get_next_line
- No se ha utilizado para generar código
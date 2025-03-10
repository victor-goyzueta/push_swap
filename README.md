# push_swap

# Objetivo general de `push_swap`

## Indicaciones

- Tienes 2 stacks, llamados `a` y `b`.
- Para empezar:
  - El stack `a` contiene una cantidad de números positivos y/o negativos, nunca duplicados.
  - El stack `b` está vacío.
- Tu programa recibirá como argumentos el stack `a` con el formato de una lista de enteros. El primer argumento debe ser el que esté encima del stack.

## Movimientos

El objetivo es ordenar los números del stack `a` en orden ascendente. Para hacerlo tienes las siguientes operaciones a tu disposición:

- `sa` **swap a**: Intercambia los dos primeros elementos del stack `a`. No hace nada si hay uno o menos elementos.
- `sb` **swap b**: Intercambia los dos primeros elementos del stack `b`. No hace nada si hay uno o menos elementos.
- `ss` **swap a** y **swap b** a la vez.
- `pa` **push a**: Toma el primer elemento del stack `b` y lo pone el primero en el stack `a`. No hace nada si `b` está vacío.
- `pb` **push b**: Toma el primer elemento del stack `a` y lo pone el primero en el stack `b`. No hace nada si `a` está vacío.
- `ra` **rotate a**: Desplaza hacia arriba todos los elementos del stack `a` una posición, de forma que el primer elemento se convierte en el último.
- `rb` **rotate b**: Desplaza hacia arriba todos los elementos del stack `b` una posición, de forma que el primer elemento se convierte en el último.
- `rr` **ra** y **rb** al mismo tiempo.
- `rra` **reverse rotate a**: Desplaza hacia abajo todos los elementos del stack `a` una posición, de forma que el último elemento se convierte en el primero.
- `rrb` **reverse rotate b**: Desplaza hacia abajo todos los elementos del stack `b` una posición, de forma que el último elemento se convierte en el primero.
- `rrr` **rra** y **rrb** al mismo tiempo.

## Normas

- Debe mostrar la lista de instrucciones más corta posible para ordenar el stack `a`, de menor a mayor, donde el número menor se sitúe en la cima del stack.
- Las instrucciones deben separarse utilizando un `\n` y nada más.
- El objetivo es ordenar el stack con el mínimo número de operaciones posible. Durante la evaluación compararemos el número de instrucciones obtenido por tu programa con un rango de instrucciones máximo. Si tu programa muestra una lista demasiado larga o si el resultado no es correcto, tu nota será 0.
- Si no se especifican parámetros, el programa no deberá mostrar nada y deberá devolver el control al usuario.
- En caso de error, deberá mostrar `Error` seguido de un `\n` en la salida de errores estándar. Algunos de los posibles errores son:
  - Argumentos que no son enteros.
  - Argumentos superiores a un entero.
  - Encontrar números duplicados.

---

# **Bonus**

- Escribe un programa llamado `checker`, que tome como argumento el stack `a` en forma de una lista de enteros. El primer argumento debe estar encima del stack. Si no se da argumento, `checker` termina y no muestra nada.
- Durante la ejecución de `checker` se esperará y leerá una lista de instrucciones, separadas utilizando `\n`. Cuando todas las instrucciones se hayan leído, `checker` las ejecutará utilizando el stack recibido como argumento.
- En cualquier otro caso, deberá mostrar `KO` seguido de un `\n` en el `stdout`.
- En caso de error, deberá mostrar `Error` seguido de un `\n` en la `stderr`. Los errores incluyen, por ejemplo:
  - Algunos o todos los argumentos no son enteros.
  - Algunos o todos los argumentos son más grandes que un número entero.
  - Hay duplicados.
  - Una instrucción no existe y/o no tiene el formato correcto.

---

# Validación de los argumentos

```c
void validate_arguments(int argc, char ***argv, char ***elements);
void check_digit(char ***elements);
void check_duplicated(char ***elements);
```

Se debe verificar que los argumentos pasados al programa cumplan los siguientes requisitos:

- Deben ser enteros.
- Deben estar dentro de los valores de `INT`.
- No deben estar duplicados.

---

# Inicialización de la Stack A

```c
typedef struct s_list
{
	void			*content;
	int			index;
	struct s_list           *next;
} t_list;

void init_stack(t_list **a, char ***elements, t_info **info);
void get_index(t_list **a);
```

Iniciamos la Stack A con los enteros que recibimos como argumentos, y obtenemos su índice relativo, es decir, el que le corresponde si la Stack estuviera ordenada ascendentemente. Esto será necesario para el algoritmo de ordenación que utilizaremos.

---

# Algoritmo (K-Sort)

```c
void size_long(t_list **a, t_list **b, t_info *info)
{
	sort_first(a, b, info);
	sort_second(a, b, info);
	check_success(a, info);
}
```

### `sort_first`

Necesitaremos `get_range` y una variable `index` inicializada a `0`.

$$range = \sqrt{TESA} * 1.4$$

*TESA: Total de enteros en la Stack A.*

Envía todos los enteros de la Stack A hacia la Stack B ordenándolos siguiendo las siguientes condiciones:

- Si el primer entero es igual o menor al índice, lo enviamos al final de la Stack B e incrementamos el índice.
- Si no, si es igual o menor al `range` más el índice, lo enviamos al principio de la Stack B e incrementamos el índice.
- Si no, si el último entero de la lista cumple alguna de estas condiciones, lo traemos al principio de la Stack A, para valorarlo en el siguiente loop.
- Si no cumple ninguna de estas condiciones, lo enviamos al final de la Stack A.

Esto nos dará como resultado la Stack B con todos los enteros estando los más grandes en el extremo.

### `sort_second`

Necesitaremos `counter` para encontrar en qué mitad de la Stack B está el número más grande y cuántos movimientos necesitaremos para tenerlo en el principio de la Stack B. Y de esta forma devolverlo a la Stack A, para que al terminar tengamos todos los enteros en la Stack A ordenados ascendentemente.


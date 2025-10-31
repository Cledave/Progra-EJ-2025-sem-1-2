# Simulador del Halcón Milenario

## Descripción

Este programa simula el movimiento del Halcón Milenario en un mapa estelar rectangular, verificando si puede llegar a su destino sin ser destruido.

## Compilación

Para compilar el programa en Windows con GCC:

```
gcc halcon_milenario.c -o halcon_milenario.exe
```

## Ejecución

```
halcon_milenario.exe
```

El programa buscará el archivo `situacioninicial.txt` en el mismo directorio y generará `situacionfinal.txt` con el resultado.

## Formato del archivo de entrada (situacioninicial.txt)

```
m               # Número de filas del mapa
n               # Número de columnas del mapa
h_fila h_col    # Posición inicial de la nave (fila, columna)
t_fila t_col    # Posición del planeta destino (fila, columna)
num_estrellas   # Número de estrellas
e1_f e1_c       # Coordenadas de cada estrella (una por línea)
e2_f e2_c
...
num_destructores # Número de destructores
d1_f d1_c       # Coordenadas de cada destructor (una por línea)
d2_f d2_c
...
orientacion     # Orientación inicial: N (norte), E (este), S (sur), O (oeste)
num_ordenes     # Número de órdenes
ordenes         # Secuencia de órdenes (A, D, I sin espacios)
```

## Órdenes disponibles

- **A** (Avanzar): La nave se mueve una casilla en la dirección actual
- **D** (Derecha): La nave gira 90° a la derecha (sin moverse)
- **I** (Izquierda): La nave gira 90° a la izquierda (sin moverse)

## Orientaciones

- **N**: Norte (arriba, disminuye fila)
- **S**: Sur (abajo, aumenta fila)
- **E**: Este (derecha, aumenta columna)
- **O**: Oeste (izquierda, disminuye columna)

## Resultados posibles

El programa genera `situacionfinal.txt` con uno de estos mensajes:

- **"Llegamos a salvo"**: La nave llegó al destino sin destruirse
- **"Nave perdida"**: La nave salió de los límites del mapa o no llegó al destino
- **"Nave destruida"**: La nave chocó con una estrella o destructor

## Ejemplo de entrada

```
5
5
0 0
4 4
2
1 1
2 2
1
3 3
N
8
AADAADAA
```

Este ejemplo crea un mapa de 5x5, con la nave en (0,0) orientada al Norte, destino en (4,4), 2 estrellas y 1 destructor, con 8 órdenes de movimiento.

## Notas importantes

- Las coordenadas van de 0 a (m-1) para filas y 0 a (n-1) para columnas
- El mapa puede ser de hasta 50x50
- La nave se destruye inmediatamente al tocar una estrella o destructor
- Intentar salir del mapa también destruye la nave

// Autor: Claudio Sepulveda
// Fecha: 29/10
// Nombre programa: Halcon-milenario

#include <stdio.h>

#define MAX_TAM 50
#define MAX_ORD 80

// Prototipos
void lectura_datos(int *columnas, int *filas, int *inicial_x, int *inicial_y,
                   int *t_x, int *t_y, int *cant_estrellas, int estrellas[][2],
                   int *cant_destructores, int destructores[][2]);
void creacion_tablero(int columnas, int filas, int inicial_x, int inicial_y,
                      int t_x, int t_y, int cant_estrellas, int estrellas[][2],
                      int cant_destructores, int destructores[][2]);

int main(void){
    int columnas, filas;
    int inicial_x, inicial_y;   // x = columna, y = fila (internamente)
    int t_x, t_y;
    int cant_estrellas, cant_destructores;
    int estrellas[MAX_TAM][2];      // [i][0]=x(col), [i][1]=y(fila)
    int destructores[MAX_TAM][2];   // idem

    lectura_datos(&columnas, &filas, &inicial_x, &inicial_y,
                  &t_x, &t_y, &cant_estrellas, estrellas,
                  &cant_destructores, destructores);

    creacion_tablero(columnas, filas, inicial_x, inicial_y,
                     t_x, t_y, cant_estrellas, estrellas,
                     cant_destructores, destructores);

    return 0;
}

void lectura_datos(int *columnas, int *filas, int *inicial_x, int *inicial_y,
                   int *t_x, int *t_y, int *cant_estrellas, int estrellas[][2],
                   int *cant_destructores, int destructores[][2]){
    FILE *situacion = fopen("Situacion_inicial.txt","r");
    if (situacion == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }

    // El archivo trae: filas;columnas  (p.ej. 9;10)
    fscanf(situacion, "%d;%d", filas, columnas);

    // El archivo trae todas las coordenadas como: fila;columna  (y;x)
    // Mapeamos a nuestras variables internas: (y -> *_y) y (x -> *_x)
    fscanf(situacion, "%d;%d", inicial_y, inicial_x);   // fila;columna
    fscanf(situacion, "%d;%d", t_y,       t_x);         // fila;columna

    fscanf(situacion, "%d", cant_estrellas);
    for (int i = 0; i < *cant_estrellas; i++) {
        int fila, col;
        fscanf(situacion, "%d;%d", &fila, &col);  // fila;columna
        estrellas[i][0] = col;  // x (columna)
        estrellas[i][1] = fila; // y (fila)
    }

    fscanf(situacion, "%d", cant_destructores);
    for (int i = 0; i < *cant_destructores; i++) {
        int fila, col;
        fscanf(situacion, "%d;%d", &fila, &col);  // fila;columna
        destructores[i][0] = col;  // x (columna)
        destructores[i][1] = fila; // y (fila)
    }

    char orientacion;
    fscanf(situacion, " %c", &orientacion);

    int num_ordenes;
    char ordenes[MAX_ORD + 1];
    fscanf(situacion, "%d", &num_ordenes);
    fscanf(situacion, "%s",  ordenes);

    fclose(situacion);
}

void creacion_tablero(int columnas, int filas, int inicial_x, int inicial_y,
                      int t_x, int t_y, int cant_estrellas, int estrellas[][2],
                      int cant_destructores, int destructores[][2]){
    char espacio[filas][columnas];

    // Inicializar
    for (int y = 0; y < filas; y++)
        for (int x = 0; x < columnas; x++)
            espacio[y][x] = ' ';

    // H  (usar siempre [y][x])
    if (inicial_x>=0 && inicial_x<columnas && inicial_y>=0 && inicial_y<filas)
        espacio[inicial_y][inicial_x] = 'H';
    else
        printf("Posición inicial fuera de rango (%d,%d)\n", inicial_x, inicial_y);

    // T
    if (t_x>=0 && t_x<columnas && t_y>=0 && t_y<filas)
        espacio[t_y][t_x] = 'T';
    else
        printf("Planeta fuera de rango (%d,%d)\n", t_x, t_y);

    // Estrellas
    for (int i=0; i<cant_estrellas; i++) {
        int ex = estrellas[i][0], ey = estrellas[i][1]; // x, y
        if (ex>=0 && ex<columnas && ey>=0 && ey<filas)
            espacio[ey][ex] = 'E';
        else
            printf("Estrella fuera de rango (%d,%d)\n", ex, ey);
    }

    // Destructores
    for (int i=0; i<cant_destructores; i++) {
        int dx = destructores[i][0], dy = destructores[i][1]; // x, y
        if (dx>=0 && dx<columnas && dy>=0 && dy<filas)
            espacio[dy][dx] = 'D';
        else
            printf("Destructor fuera de rango (%d,%d)\n", dx, dy);
    }

    // Imprimir
    printf("\n--ESPACIO--\n");
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++)
            printf("%c ", espacio[y][x]);
        printf("\n");
    }
}

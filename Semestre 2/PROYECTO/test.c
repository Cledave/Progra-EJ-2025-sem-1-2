#include <stdio.h>

#define MAX 50
#define MAX_ORDENES 80

int main() {
    FILE *archivo;
    archivo = fopen("situacion_inicial.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int filas, columnas;
    int hx, hy; // Posición Halcón
    int tx, ty; // Posición Planeta
    int num_estrellas;
    int num_destructores;
    int estrellas[MAX][2];
    int destructores[MAX][2];
    char orientacion;
    int num_ordenes;
    char ordenes[MAX_ORDENES + 1]; // +1 para el '\0'

    // Lectura según el formato del archivo
    fscanf(archivo, "%d;%d", &filas, &columnas);
    fscanf(archivo, "%d;%d", &hx, &hy);
    fscanf(archivo, "%d;%d", &tx, &ty);

    fscanf(archivo, "%d", &num_estrellas);
    for (int i = 0; i < num_estrellas; i++) {
        fscanf(archivo, "%d;%d", &estrellas[i][0], &estrellas[i][1]);
    }

    fscanf(archivo, "%d", &num_destructores);
    for (int i = 0; i < num_destructores; i++) {
        fscanf(archivo, "%d;%d", &destructores[i][0], &destructores[i][1]);
    }

    fscanf(archivo, " %c", &orientacion);  // Espacio antes de %c para saltar salto de línea
    fscanf(archivo, "%d", &num_ordenes);
    fscanf(archivo, "%s", ordenes);

    fclose(archivo);

    // --- Comprobación de lectura ---
    printf("Mapa: %d filas x %d columnas\n", filas, columnas);
    printf("Halcón: (%d, %d)\n", hx, hy);
    printf("Planeta: (%d, %d)\n", tx, ty);
    printf("Estrellas: %d\n", num_estrellas);
    for (int i = 0; i < num_estrellas; i++) {
        printf("  Estrella %d: (%d, %d)\n", i + 1, estrellas[i][0], estrellas[i][1]);
    }
    printf("Destructores: %d\n", num_destructores);
    for (int i = 0; i < num_destructores; i++) {
        printf("  Destructor %d: (%d, %d)\n", i + 1, destructores[i][0], destructores[i][1]);
    }
    printf("Orientación inicial: %c\n", orientacion);
    printf("Órdenes (%d): %s\n", num_ordenes, ordenes);

    return 0;
}
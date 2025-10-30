// Autor: Claudio Sepulveda
// Fecha: 29/10
// Nombre programa: Halcon-milenario

// bibliotecas
#include <stdio.h>

// define
#define MAX_TAM 50
#define MAX_ORD 80

// Prototipo de funciones

void lectura_datos(int *filas, int *columnas, int *inicial_x, int *inicial_y, 
                   int *planeta_x, int *planeta_y, int *cant_estrellas, int estrellas[][2], 
                   int *cant_destructores, int destructores[][2]);

void creacion_tablero(int filas, int columnas, int inicial_x, int inicial_y,
                      int planeta_x, int planeta_y, int cant_estrellas, int estrellas[][2], 
                      int cant_destructores, int destructores[][2]);



void escribir_resultado(const char *frase);


int main(){
    
    int columnas, filas;
    int inicial_x, inicial_y;
    int planeta_x, planeta_y;
    int cant_estrellas, cant_destructores;
    int estrellas[MAX_TAM][2];
    int destructores[MAX_TAM][2];

    char orientacion;
    int num_ordenes;
    char ordenes[MAX_ORD+1];

    lectura_datos(&filas, &columnas, &inicial_x, &inicial_y, 
                  &planeta_x, &planeta_y, &cant_estrellas, estrellas, 
                  &cant_destructores, destructores);
    
    creacion_tablero(filas,columnas,inicial_x,inicial_y,
                     planeta_x,planeta_y,cant_estrellas,estrellas,
                     cant_destructores,destructores);
    
    return 0;
}

void lectura_datos(int *filas, int *columnas, int *inicial_x, int *inicial_y, int *planeta_x, int *planeta_y, int *cant_estrellas, int estrellas[][2], int *cant_destructores, int destructores[][2]){
    //crea un puntero al archivo y despues le asigna un nombre
    FILE *situacion;
    situacion = fopen("Situacion_inicial.txt","r");
    if (situacion == NULL) {            
        printf("No se puede abrir el archivo.");
    }   
    // Escanea linea por linea y va guardando segun el formato dado en el txt
    fscanf(situacion, "%d;%d",filas,columnas);
    fscanf(situacion, "%d;%d",inicial_y,inicial_x);
    fscanf(situacion, "%d;%d",planeta_y,planeta_x);
        
    fscanf(situacion, "%d", cant_estrellas);
        for (int i=0; i < *cant_estrellas;i=i+1) {
            fscanf(situacion, "%d;%d", &estrellas[i][0], &estrellas[i][1]);
        }

    fscanf(situacion,"%d", cant_destructores);
        for (int i=0; i < *cant_destructores;i=i+1) {
            fscanf(situacion, "%d;%d", &destructores[i][0], &destructores[i][1]);
        }
    
    char orientacion;
        fscanf(situacion," %c",&orientacion);
    
    int num_ordenes;
    char ordenes[MAX_ORD + 1];
        fscanf(situacion,"%d",&num_ordenes);
        fscanf(situacion,"%s",&ordenes);;
    
    fclose(situacion);
/*
    printf("%d-%d",columnas,filas);
    printf("\n%d-%d",inicial_x,inicial_y);
    printf("\n%d-%d",planeta_x,planeta_y);
    printf("\n%d\n",cant_estrellas);
    for (int i = 0; i < cant_estrellas; i++) {
        printf("%d,%d\n",estrellas[i][0],estrellas[i][1]);
    }
    printf("%d\n",cant_destructores);
    for (int i = 0; i < cant_destructores; i++) {
        printf("%d,%d\n",destructores[i][0],destructores[i][1]);
    }
    printf("%c",orientacion);
    printf("\n%d\n",num_ordenes);
    printf("%s",ordenes);
*/
}

void creacion_tablero(int filas, int columnas, int inicial_x, int inicial_y, int planeta_x, int planeta_y, int cant_estrellas, int estrellas[][2], int cant_destructores, int destructores[][2]){
    
    char espacio[filas][columnas];

    // llenar con espacios vacios
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            espacio[y][x] = ' ';
        }
    }

    if (inicial_x>=0 && inicial_x<columnas && inicial_y>=0 && inicial_y<filas){     
        espacio[inicial_y][inicial_x] = 'H';
    } else {
        printf("posicion inicial fuera de rango (%d,%d)\n", inicial_x, inicial_y);
    }

    if (planeta_x>=0 && planeta_x<columnas && planeta_y>=0 && planeta_y<filas){
        espacio[planeta_y][planeta_x] = 'T';
    } else {
        printf("planeta fuera de rango (%d,%d)\n", planeta_x, planeta_y);
    }

    // Estrellas
    for (int i=0; i < cant_estrellas; i++) {
        int estrella_y = estrellas[i][0];
        int estrella_x = estrellas[i][1];
        if (estrella_x>=0 && estrella_x<columnas && estrella_y>=0&&estrella_y<filas){
            espacio[estrella_y][estrella_x] = 'E';
        } else {
            printf("etrella fuera de rango (%d,%d)\n", estrella_y, estrella_x);
        }
    }

    // Destructores 
    for (int i=0; i<cant_destructores; i++) {
        int destructor_y = destructores[i][0];
        int destructor_x = destructores[i][1];
        if (destructor_x >= 0 && destructor_x < columnas && destructor_y >= 0 && destructor_y < filas){
            espacio[destructor_y][destructor_x] = 'D';
        } else {
            printf("destructor fuera de rango (%d,%d)\n", destructor_y, destructor_x);
        }
    }

    // imprimir
    printf("\n--ESPACIO--\n");
    for (int y = 0; y < filas; y++) {
        for (int x = 0; x < columnas; x++) {
            printf("%c ", espacio[y][x]);
        }
        printf("\n");
    }
}



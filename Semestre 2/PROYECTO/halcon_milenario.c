// Autor: Claudio Sepulveda
// Fecha: 29/10
// Nombre programa: Halcon-milenario

// bibliotecas
#include <stdio.h>

// definiciones
#define MAX_TAM 50
#define MAX_ORD 80

// Prototipo de funciones

void lectura_datos(int *filas, int *columnas, int *inicial_x, int *inicial_y, 
                   int *planeta_x, int *planeta_y, int *cant_estrellas, int estrellas[][2], 
                   int *cant_destructores, int destructores[][2],
                   char *orientacion, int *num_ordenes, char ordenes[]);

void creacion_tablero(int filas, int columnas, int inicial_x, int inicial_y,
                      int planeta_x, int planeta_y, int cant_estrellas, int estrellas[][2], 
                      int cant_destructores, int destructores[][2]);

int movimientos(int filas, int columnas, int *x, int *y, char *orientacion,const char ordenes[], int num_ordenes,int planeta_x, int planeta_y,
                int cant_estrellas, int estrellas[][2],int cant_destructores, int destructores[][2]);

void escribir_resultado(int rc);


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
                  &cant_destructores, destructores,
                  &orientacion, &num_ordenes, ordenes);
    
    
    int x = inicial_x; 
    int y = inicial_y;
    char ori = orientacion;
    int rc_final = movimientos(filas, columnas, &x, &y, &ori, ordenes, num_ordenes,planeta_x,planeta_y,cant_estrellas,estrellas,cant_destructores,destructores);
    escribir_resultado(rc_final);
    creacion_tablero(filas,columnas,inicial_x,inicial_y,
                     planeta_x,planeta_y,cant_estrellas,estrellas,
                     cant_destructores,destructores);
    
    
    return 0;
}

void lectura_datos(int *filas, int *columnas, int *inicial_x, int *inicial_y, int *planeta_x, int *planeta_y,
                   int *cant_estrellas, int estrellas[][2], int *cant_destructores, int destructores[][2],
                   char *orientacion, int *num_ordenes, char ordenes[]){

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
    
    fscanf(situacion," %c",orientacion);
    fscanf(situacion,"%d", num_ordenes);
    fscanf(situacion,"%s", ordenes);;
    
    //Cierra el archivo que se abrio en solo lectura
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

void creacion_tablero(int filas, int columnas, int inicial_x, int inicial_y, int planeta_x, int planeta_y, 
                      int cant_estrellas, int estrellas[][2], int cant_destructores, int destructores[][2]){
    
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
            printf("estrella fuera de rango (%d,%d)\n", estrella_y, estrella_x);
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

int movimientos(int filas, int columnas, int *x, int *y, char *orientacion,const char ordenes[], int num_ordenes,int planeta_x, int planeta_y,
                int cant_estrellas, int estrellas[][2],int cant_destructores, int destructores[][2]){
    
    for (int i=0;i<cant_destructores;i++){
        if (destructores[i][1]==*x && destructores[i][0]==*y) return 3;
    }
    for (int i=0;i<cant_estrellas;i++){
        if (estrellas[i][1]==*x && estrellas[i][0]==*y) return 3;
    }
    if (*x==planeta_x && *y==planeta_y){
        return 1;
    } 

    for (int i = 0; i < num_ordenes; i++) {
        char orden = ordenes[i];
    if (orden == 'I') {                 
        if  (*orientacion == 'N'){
            *orientacion = 'O';
        } else if (*orientacion == 'O'){
            *orientacion = 'S';
        } else if (*orientacion == 'S'){
            *orientacion = 'E';
        } else if (*orientacion == 'E'){
            *orientacion = 'N';
        } else {
            return 2;
        }
        continue;
    } 
    else if (orden == 'D') {        
        if  (*orientacion == 'N'){
            *orientacion = 'E';
        } else if (*orientacion == 'E'){
            *orientacion = 'S';
        } else if (*orientacion == 'S'){
            *orientacion = 'O';
        } else if (*orientacion == 'O'){
            *orientacion = 'N';
        } else {
            return 2;
        }
        continue;
    } 
    else if (orden == 'A') {            
        int direccion_x = 0, direccion_y = 0;
        if (*orientacion == 'N'){
            direccion_y = -1;
        } else if (*orientacion == 'S'){
            direccion_y =  1;
        } else if (*orientacion == 'E'){
            direccion_x =  1;
        } else if (*orientacion == 'O'){
            direccion_x = -1;
        } else {
            return 2;
        }

        int nuevo_x = *x + direccion_x;
        int nuevo_y = *y + direccion_y;

        if (nuevo_x<0 || nuevo_x>=columnas || nuevo_y<0 || nuevo_y>=filas) {
            return 2;
        }
        *x = nuevo_x;
        *y = nuevo_y;
        
        for (int j=0;j<cant_destructores;j++){
            if (destructores[j][1]==*x && destructores[j][0]==*y){
                return 3;
            }
        }
        for (int j=0;j<cant_estrellas;j++){
            if (estrellas[j][1]==*x && estrellas[j][0]==*y){
                return 3;
            }
        }
        if (*x==planeta_x && *y==planeta_y) {
            return 1;
        }
        } else {
            return 2;
        }
    }
return 0;
}

void escribir_resultado(int rc){
    FILE *final = fopen("situacion_final.txt", "w");
    if (rc == 1) {
        fprintf(final, "%s", "Llegamos a salvo");
        fclose(final);
    } else if (rc == 3) {
        fprintf(final, "%s", "Nave destruida");
        fclose(final);
    } else {
        fprintf(final, "%s", "Nave perdida");
        fclose(final);
    }
}
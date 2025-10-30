// Autor: Claudio Sepulveda
// Fecha: 29/10
// Nombre programa: Halcon-milenario

// bibliotecas
#include <stdio.h>

// define
#define MAX_TAM 50
#define MAX_ORD 80

// Prototipo de funciones
void lectura_datos();
int tablero_movimientos();

int main(){
    lectura_datos();
    return 0;
}

void lectura_datos(){
    FILE *situacion;
    situacion = fopen("Situacion_inicial.txt","r");
    if (situacion == NULL) {
        printf("No se puede abrir el archivo.");
    }   

    int columnas, filas;
        fscanf(situacion, "%d;%d",&columnas,&filas);

    int inicial_x, inicial_y;
        fscanf(situacion, "%d;%d",&inicial_x,&inicial_y);
    
    int t_x,t_y;
        fscanf(situacion, "%d;%d",&t_x,&t_y);
    
    int cant_estrellas,estrellas [MAX_TAM][2];
        fscanf(situacion, "%d",&cant_estrellas);
        for (int i=0; i<cant_estrellas;i=i+1) {
            fscanf(situacion, "%d;%d", &estrellas[i][0], &estrellas[i][1]);
        }

    int cant_destructores, destructores [MAX_TAM][2];
        fscanf(situacion,"%d",&cant_destructores);
        for (int i=0; i<cant_destructores;i=i+1) {
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
    printf("\n%d-%d",t_x,t_y);
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
int tablero_movimientos(){

}

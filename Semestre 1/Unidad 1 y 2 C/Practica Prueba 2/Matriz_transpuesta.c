#include <stdio.h>
int main(){
    int filas;
    int columnas;

    printf("Define el tamaño de la matriz (filas):  \n");
    scanf("%d",&filas);
    printf("Define el tamaño de la matriz (columnas):  \n");
    scanf("%d",&columnas);

    int matriz[filas][columnas];
    int transpuesta[columnas][filas];

    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            printf("Que numero quieres en la posicion [%d][%d]:   \n",a,b);
            scanf("%d",&matriz[a][b]);
        }
    }
    printf("Tu matriz es:   \n");
    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            printf("%d\t",matriz[a][b]);
        }
        printf("\n");
    }
    printf("Tu matriz transpuesta es    \n");
    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            transpuesta[b][a]=matriz[a][b];
        }
    }
    for (int a = 0; a < columnas; a++) {
        for (int b = 0; b < filas; b++) {
            printf("%d\t", transpuesta[a][b]);
        }
        printf("\n");
    }
}
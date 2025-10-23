#include <stdio.h>
int main(){
    int filas;
    int columnas;   
    printf("Filas:\t\n");
    scanf("%d",&filas);
    printf("Columnas:\t\n");
    scanf("%d",&columnas);

    int matriz[filas][columnas];

    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            printf("Ingresa tu [%d][%d]:\t",a,b);
            scanf("%d",&matriz[a][b]);
        }
    }
    printf("Matriz\n");
    for (int a=0;a<filas;a=a+1){
        for (int b=0;b<columnas;b=b+1){
            printf("%d\t",matriz[a][b]);
        }
    printf("\n");
    }
    if (filas>columnas){
        for (int a=0;a<columnas;a=a+1){
            printf("Diagonal pricipal:\t%d\n",matriz[a][a]);
            printf("Diagonal secundaria:\t%d\n",matriz[a][(columnas-1)-a]);
        }
    } else if (columnas>=filas){
        for (int a=0;a<filas;a=a+1){
            printf("Diagonal pricipal:\t%d\n",matriz[a][a]);
            printf("Diagonal secundaria:\t%d\n",matriz[a][(filas-1)-a]);
        }
    }
}
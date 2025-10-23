#include <stdio.h>
int main(){
    int x;
    int y;

    printf("Define el tamaño de la matriz (X):  \n");
    scanf("%d",&x);
    printf("Define el tamaño de la matriz (Y):  \n");
    scanf("%d",&y);

    int matriz[x][y];

    for (int a=0;a<y;a=a+1){
        for (int b=0;b<x;b=b+1){
            printf("Que numero quieres en la posicion [%d][%d]:   \n",a,b);
            scanf("%d",&matriz[a][b]);
        }
    }
    printf("Tu matriz es:   \n");
    for (int a=0;a<y;a=a+1){
        for (int b=0;b<x;b=b+1){
            printf("%d\t",matriz[a][b]);
        }
        printf("\n");
    }
    printf("\n");

    for (int a=0;a<y;a=a+1){
        int suma=0;
        for (int b=0;b<x;b=b+1){
            suma = suma + matriz[a][b];
        }
        printf("Suma de la fila %d: %d\n", a, suma);
    }
    for (int a=0;a<x;a=a+1){
        int suma_2=0;
        for (int b=0;b<y;b=b+1){
            suma_2 = suma_2 + matriz[a][b];
        }
        printf("Suma de la columnas es %d: %d\n", a, suma_2);
    }
}

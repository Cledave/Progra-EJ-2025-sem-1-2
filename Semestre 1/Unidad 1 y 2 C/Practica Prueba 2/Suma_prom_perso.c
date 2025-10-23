#include <stdio.h>
int main(){
    int x;
    int y;

    printf("Define el tamaño de la matriz (X):  \n");
    scanf("%d",&x);
    printf("Define el tamaño de la matriz (Y):  \n");
    scanf("%d",&y);

    float matriz[x][y];

    for (int a=0;a<y;a=a+1){
        for (int b=0;b<x;b=b+1){
            printf("Que nota te sacaste en la prueba? [%d][%d]:   \n",a,b);
            scanf("%f",&matriz[a][b]);
        }
    }
    printf("Tus notas son:   \n");
    for (int a=0;a<y;a=a+1){
        for (int b=0;b<x;b=b+1){
            printf("%.0f\t",matriz[a][b]);
        }
        printf("\n");
    }

    float promedio;
    float cantidad_notas=x*y;
    float suma=0.0;

    for (int a=0;a<y;a=a+1){
        for (int b=0;b<x;b=b+1){
        suma = suma + matriz [a][b];
        }
    }
    promedio=suma/cantidad_notas;
    printf("Tu promedio actual es:\t%.2f\n",promedio);
    return(0);


}
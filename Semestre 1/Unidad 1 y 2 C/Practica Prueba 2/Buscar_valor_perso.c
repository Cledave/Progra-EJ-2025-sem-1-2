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

    int Num;
    printf("Que numero quieres buscar?\n");
    scanf("%d",&Num);

    for (int a=0;a<y;a=a+1){
        for (int b=0;b<x;b=b+1){
            if (matriz[a][b]==Num){
                printf("Tu numero se encuentra en la posicion[%d][%d]\n",a,b);
                return(0);
            }
        }
    }
    printf("Tu numero no se encuentra en la matriz\n");
}

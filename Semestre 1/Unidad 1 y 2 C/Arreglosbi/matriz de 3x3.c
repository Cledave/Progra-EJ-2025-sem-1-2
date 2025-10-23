#include <stdio.h>

int main(){
    int matriz [3][3];
    int a,b;
    printf("Ingrese 9 numeros para llenar la matriz\n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("Elemento [%d][%d]: ",a,b);
            scanf("%d",&matriz[a][b]);
        }
    }

    int num;
    printf("\nQue numero quieres buscar?\n");
    scanf("%d",&num);

    for (a = 0;a<3;a=a+1){
        for (b = 0;b<3;b=b+1){
            if (matriz[a][b]==num){
                printf("Tu numero se encuentra en la posicion %d,%d", a,b);
                return(0);
            }
        }
    }
    printf("Tu numero no se encuentra en la matriz!");
    return(0);
}    
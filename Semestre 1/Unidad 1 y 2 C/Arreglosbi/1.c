#include <stdio.h>

int main(){
    int matriz [3][3];
    
    printf("Ingrese 9 numeros para llenar la matriz\n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("Elemento [%d][%d]: ",a,b);
            scanf("%d",&matriz[a][b]);
        }
    }
    //Mostrar matriz
    printf("\nMatriz\n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("%d\t",matriz[a][b]);
        }
        printf("\n");
    }

}
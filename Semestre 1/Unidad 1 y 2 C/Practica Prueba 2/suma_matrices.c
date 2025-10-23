#include <stdio.h>

int main(){

    int matriz_1 [3][3];
    int matriz_2 [3][3];
    int matriz_suma [3][3];

    printf("Matriz 1:\n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("Que numero quieres en el espacio[%d][%d]:\t",a,b);
            scanf("%d",&matriz_1[a][b]);
        }
    }
    printf("Matriz 2:\n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("Que numero quieres en el espacio[%d][%d]:\t",a,b);
            scanf("%d",&matriz_2[a][b]);
        }
    }
    printf("\nMatriz1:\n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("%d\t",matriz_1[a][b]);
        }
    printf("\n");
    }
    printf("\nMatriz2:\n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("%d\t",matriz_2[a][b]);
        }
    printf("\n");
    }

    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            matriz_suma[a][b]=matriz_1[a][b]+matriz_2[a][b];
        }
    }
    printf("\n  Matriz Sumada \n");
    for (int a=0;a<3;a=a+1){
        for (int b=0;b<3;b=b+1){
            printf("%d\t",matriz_suma[a][b]);
        }
        printf("\n");
    }
return(0);
}
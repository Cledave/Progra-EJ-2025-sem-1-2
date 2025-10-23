#include <stdio.h>

int main(){
    int X;
    int Y;
    printf("Eje X");
    scanf("%d",&X);
    printf("Eje Y");
    scanf("%d",&Y);

    int matriz[X][Y];

    for(int a=0;a<X;a=a+1){
        for (int b=0;b<Y;b=b+1){
            printf("Que numero quieres en [%d][%d]",a,b);
            scanf("%d",&matriz[a][b]);
        }
    }

    int num;
    printf("Numeros mayores a?:      ");
    scanf("%d",&num);

    int contador_mayor=0;
    int contador_menor=0;

    for (int e=0;e<X;e=e+1){
        for (int f=0;f<Y;f=f+1){
            if (matriz[e][f]>num){
                contador_mayor=contador_mayor+1;
            }
        }
    }

    for (int g=0;g<X;g=g+1){
        for (int h=0;h<Y;h=h+1){
            if (matriz[g][h]<num){
                contador_menor=contador_menor+1;
            }
        }
    }
    for (int c=0;c<X;c=c+1){
        for (int d=0;d<Y;d=d+1){
            printf("%d\t",matriz[c][d]);
        }
        printf("\n");
    }
    printf("Tienes %d mayores a %d en la matriz\n",contador_mayor,num);
    printf("Tienes %d menores a %d en la matriz\n",contador_menor,num);

    return(0);


}
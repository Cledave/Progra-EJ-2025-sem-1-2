#include <stdio.h>

int main(){
    int matriz [3][3] = {
        {6,20,23},
        {78,15,56},
        {5,8,80}
    };
    int a,b;
    int num_mayor = 0;
    int contador=0;

    for (a = 0;a<3;a=a+1){
        for (b = 0;b<3;b=b+1){
            if (matriz[a][b]>18){
                contador=contador+1;
                printf("%d\t",matriz[a][b]);
            }
        }
    }
    printf("\n%d",contador);
    return(0);
}    
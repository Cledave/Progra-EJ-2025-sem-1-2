#include <stdio.h>

int main(){

    int matriz[4][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };
    for (int a=0;a<4;a=a+1){
        int suma = 0;
        for (int b=0;b<3;b=b+1){
            suma = suma + matriz[a][b];
        }
        printf("Suma de la fila %d: %d \n",a,suma);
    }
    return(0);
}
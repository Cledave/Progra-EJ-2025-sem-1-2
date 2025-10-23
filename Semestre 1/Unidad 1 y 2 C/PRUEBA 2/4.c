#include <stdio.h>

int main(){
    int contador=0;             //Variable aux para ayudame a saber si existe el numero en el arreglo
    int matriz [4][4] = {
        {5,8,12,7},
        {6,7,14,7},
        {9,2,7,0},
        {3,7,11,4}
    };
    int num;
    printf("Valor critico a buscar:\t");
    scanf("%d",&num);

    printf("El valor %d se encuentra en las siguientes posiciones: \n",num);
    for (int a=0;a<4;a=a+1){
        for (int b=0;b<4;b=b+1){
            if (matriz[a][b]==num){ //compara cada num del arreglo con el mio
                printf("[%d][%d]\n",a,b);
                contador=contador+1;
            }
        }
    }
    if (contador==0){
        printf("NINGUNA!!");
        return(0);
    }
}
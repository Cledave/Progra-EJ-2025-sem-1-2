#include <stdio.h>
int main(){
    int numero=0;
    int i=1;
    int resul_mult;

    printf("Ingresa un numero entre 1 y 10\n");
    scanf("%d",&numero);
    if (numero<1||numero>10) {
        printf("numero fuera de rango");
        return(0);
    }
    printf("Tabla de multiplicar del 1 al 10 para %d\n",numero);
    for (i;i<=10;i=i+1) {
        resul_mult=numero*i;
        printf("%d\n", resul_mult);

    }


}
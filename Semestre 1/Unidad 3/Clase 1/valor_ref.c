#include <stdio.h>

void porvalor(int n){
    n = n*2;
    printf("Dentro de porvalor N = %d\n",n);
}

void porreferencia (int *n){
    *n = *n*2;
    printf("Dentro de ref N = %d\n",*n);
}


int main(){
    int a;
    int b;
    printf("Ingresa tus numeros:\n");
    printf("Numero 1:\n");
        scanf("%d",&a);
    printf("Numero 2:\n");
        scanf("%d",&b);
    printf("\n");

    porvalor(a);
    printf("Despues de PorValor a = %d\n",a); //No cambia

    porreferencia(b);
    printf("Despues de ref b = %d\n",b); //Si cambia

    return(0);
}
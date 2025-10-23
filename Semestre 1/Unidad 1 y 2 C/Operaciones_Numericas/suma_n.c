#include<stdio.h>

int main(  ) {
    int n, i;
    int suma=0;

    printf("introduce un numero entero positivo:    ");
    scanf("%d",&n);

    for (i=1; i<=n; i++) {
        suma += i;
    }

    printf("la suma de los numeros de 1 a %d es: %d\n",n ,suma);

    return 0;
}
#include<stdio.h>

int main( ) {
    int numero;

    printf("Numero:    ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("Numero %d es Par\n", numero);
    } else {
        printf("Numero %d es Impar\n", numero);
    }
return 0;

}
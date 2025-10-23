#include <stdio.h>

int main() {
    int num1, num2, suma;

    printf("Introduce el primer numero:");
    scanf("%d", &num1);

    printf("Introduce el segundo numero:");
    scanf("%d", &num2);

    suma= num1 + num2;

    printf("La suma de ambos numeros es:%d\n",suma);

    return 0;

}
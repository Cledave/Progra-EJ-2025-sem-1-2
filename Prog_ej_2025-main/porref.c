#include <stdio.h>

void cuadrado(int *);

int main(){
    int a = 5;
    printf("Valor de a: %d\n", a);
    cuadrado(&a);
    printf("Valor de a: %d\n", a);    
    return 0;
}

void cuadrado(int *a){
    *a = *a * *a;
}
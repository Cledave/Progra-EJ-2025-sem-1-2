#include <stdio.h>

void leer_datos (int *n1,int *n2, int *n3);
int maximo (int n1, int n2, int n3);

int main(){
    int n1;
    int n2;
    int n3;
    printf ("Bienvenido!\n");
    leer_datos (&n1,&n2,&n3);
    printf("%d",maximo (n1,n2,n3)); 
}

/*
Definicion de funciones
*/

void leer_datos (int *n1, int *n2, int *n3){
    printf ("Ingrese primer valor:\t");
    scanf("%d",n1);
    printf ("Ingrese segundo valor:\t");
    scanf("%d",n2);
    printf ("Ingrese tercer valor:\t");
    scanf("%d",n3);
}

int maximo (int n1, int n2, int n3) {
    if (n1>n2 && n1>n3){
        return n1;
    }
    if (n2>n1 && n2>n3){
        return n2;
    }
    if (n3>n2 && n3>n1){
        return n3;
    }
}
//Suma de 2 o mas numeros
//Primero pregunta por numero 1, despues numero 2, y asi hasta el infinito, se detiene si pones 0.

#include <stdio.h>
int main () {
    int numero=1;
    int num=0;

    printf ("Por favor introduce un numero, si no hay mas numeros que sumar coloca 0\n");
    while (numero!=0) {
        scanf ("%d",&numero);
    num=num +numero;

    }
printf ("El resultado final es %d",num);
}
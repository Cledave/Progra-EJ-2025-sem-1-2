//crea un programa que te detecte si el numero que introdujiste es impar o par
//que el programa no se detenga hasta que alguien introduzca un 0

#include <stdio.h>
int main() {
    int num=1;

    printf("Ingresa un numero, que no sea cero\n");
    while (num!=0) {
    scanf("%d", &num);
        if (num==0) {
            printf ("Programa terminado");
            return(0);
        }
        if ((num%2)==0) {
            printf ("Numero %d es par\n\n", num);
        } else {
            printf ("Numero %d es impar\n\n", num);
        }
    }
}
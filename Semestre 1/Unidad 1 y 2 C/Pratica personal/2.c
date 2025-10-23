/* Validar que sea un numero que se encuentra entre 0 y 10 y repetir hasta que se salga del limite*/

#include <stdio.h>
int main() {
float num;

printf("Ingresa un numero entre 0 y 10\n");
scanf("%f",&num);

    while (num>=0 && num<=10)   {                   //Podemos usar && y ||, el primero es AND y el segundo es OR
        printf("El numero esta dentro del rango, bien!!\n\n");
        printf("Ingresa un numero entre 0 y 10\n");
        scanf("%f",&num);
    }

printf("El numero esta fuera de rango!");
return(0);
}
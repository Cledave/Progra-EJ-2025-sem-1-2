/* 
Programa que solicite 2 numeross y los compare para saber si son iguales o no, acepta float y valida si son numeros validos o no
*/
#include <stdio.h>
int main() {
float num_1;
float num_2;

printf("Ingresa primer numero\n");
    scanf("%f",&num_1);
printf("Ingresa segundo numero\n");
    scanf("%f",&num_2);

if (num_1==num_2){
    printf("Ambos numeros son iguales!!!\n");
} else if (num_1>num_2) {
    printf("Numero 1 es mayor");
} else if (num_1<num_2) {
    printf("Numero 2 es mayor");
}
return(0);
}
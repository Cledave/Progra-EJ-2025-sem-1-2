//suma simple de 2 numeros, primero pregunta por 1 y despues por el otro

#include <stdio.h>
int main() {
    int num;
    int num2;
    int suma;

    printf("Primer numero\n");
    scanf("%d",&num);
    printf("Segundo numero\n");
    scanf("%d",&num2);
    suma=num+num2;
    printf("La suma de ambos es %d",suma);

return(0);


}
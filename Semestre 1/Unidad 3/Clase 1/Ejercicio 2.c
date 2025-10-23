#include <stdio.h>

//EL DOBLE DE UN NUMERO

int doble(int a){
    return a = a*2;
}

int main(){
    int b;
    printf("Coloca tu numero:   ");
    scanf("%d",&b);

    int doble_2 = doble(b);
    printf("El doble de tu numero es: %d\n",doble_2);
    return(0);
}
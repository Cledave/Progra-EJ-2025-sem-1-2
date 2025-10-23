//crear un programa que detecte cuando se acaban las existencias de x producto
// e imprima un mensaje para reponerlo ademas de cerrar el programa

#include <stdio.h>
int main (){
    int existencias;
    int necesito;
    printf("Cuantas existencias en total?\n");
        scanf("%d",&existencias);
    printf("Cuanto quieres retirar?\n");
    while (existencias>0)  {
        scanf("%d",&necesito);
        existencias=existencias-necesito;
        printf("Quedan %d\n",existencias);
    }
    
    printf("Reponer existencias");
    return(0);

}
#include <stdio.h>

//Definicion de la funcion
int sumar(int a, int b){
    return a + b;
} 

int main(){
    int g;    
    int h;
    printf("Ingresa tus numeros:\n");
    printf("Numero 1:\n");
        scanf("%d",&g);
    printf("Numero 2:\n");
        scanf("%d",&h);
    int resultado = sumar (g,h);
    printf("Resultado:%d\n",resultado);
    return(0);
}

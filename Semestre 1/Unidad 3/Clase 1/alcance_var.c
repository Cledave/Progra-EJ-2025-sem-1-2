#include <stdio.h>

int x = 10; //variable global 

void mostrar(){
    int y = 5  //variable local
    //ambas variables estan accesibles desde aqui
    printf("x=%d, y=%d\n",x,y);
    }

int main(){
    mostrar():

    //aqui 'x' es accesible pero 'y' no lo es
    printf("x=%d, y=%d\n",x,y);//error: y no esta declarada en este ambito
    printf("x=%d\n",x); // este si funciona
    return(0);
}
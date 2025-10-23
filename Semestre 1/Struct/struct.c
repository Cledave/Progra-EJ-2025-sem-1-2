#include <stdio.h>

struct persona {
    char nombre[10];
    int edad;
};

int main(){
    struct persona p1 = {"Ana",20};
    printf("Nombre: %s, Edad:%d\n",p1.nombre,p1.edad);
    return(0);
}
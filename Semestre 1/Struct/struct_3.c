#include <stdio.h>

struct persona {
    char nombre[30];
    int edad;
};

void mostrarpersona(struct persona p){
    printf("Nombre: %s", p.nombre);
    printf("Edad: %d", p.edad);
}

struct persona cambiaredad(struct persona p,int nuevaedad){
    p.edad = nuevaedad;
    return (p);
}
int main(){
    struct persona p1 = {"Carla ", 21};

    printf("Antes del cambio:\n");
    mostrarpersona(p1);

    p1 = cambiaredad(p1, 30);
    printf("\nDespues del cambio:\n");
    mostrarpersona(p1);

    return(0);
}
    

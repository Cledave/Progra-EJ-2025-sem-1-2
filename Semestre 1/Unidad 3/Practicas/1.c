#include <stdio.h>
    struct Persona
    {
        char Nombre[100];
        int edad;
        float estatura;
    };

int main(){
    struct Persona datos[5] = {{"Anais",32,1.83},{"Juan",43,1.43},{"Luisa",41,1.76},{"Ana",13,5.32},{"Hamari",16,1.53}};
    for (int i=0;i<5;i=i+1){
    printf("Nombre: %s\nEdad: %d\nEstatura: %.2f\n",datos[i].Nombre,datos[i].edad,datos[i].estatura);
    printf("\n");
    }
}
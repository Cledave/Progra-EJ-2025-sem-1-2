#include <stdio.h>

struct persona {
    char nombre[30];
    int edad;
};

int main(){
    struct persona personas[2] = {{"lucas",22},{"Elena",19}};


    for (int i = 0; i < 2; i = i + 1) {
        printf("Nombre: %s, Edad: %d\n", personas[i].nombre, personas[i].edad);
    }

    return 0;
}
    

#include <stdio.h>

#define TAM 5  //Definir TAM para usarlo como 5

struct Estudiante {                 //crea el struc estudiante que contiene, nombre,edad y promedio
    char nombre[50];
    int edad;
    float promedio;
};

float calcular_promedio_curso(struct Estudiante alumnos[], int n) { //Crea una funcion que calcula el promedio del curso
    float suma = 0;                                                 //En este float se van a ir sumando todas las notal de los alumnos
    for (int i = 0; i < n; i++) {                                   
        suma += alumnos[i].promedio;                                //Hace que las notas se sumen
    }
    return suma / n;                                                //La suma de todas las notas divididas en el numero de alumnos te da su promedio
}

int buscar_mejor_estudiante(struct Estudiante alumnos[], int n) {   //Crea una funcion para buscar al mejor estudiante
    int indice = 0;                                                 //El indice es la posicion en la que esta el estudiante con mejor nota
    for (int i = 1; i < n; i++) {
        if (alumnos[i].promedio > alumnos[indice].promedio) {       //Compra las notas de los 5 alumnos una a una para saber cual es mayor
            indice = i;                                             //Si resulta ser mayor que la anterior la nota no se reemplaza si no que se guarda el numero del indice
        }
    }
    return indice;                                                  //Cuando hago una funcion fuera de un void() necesito poner el return variable, si no no va funcionar
}

int main() {
    struct Estudiante curso[TAM];                                   //Llamo al struct y establezco el limite con TAM

    for (int i = 0; i < TAM; i++) {                                 //Ciclo FOR que recorre y guarlas las variables en el struct
        printf("Nombre: ");
        scanf(" %[^\n]", curso[i].nombre);                          //Lee caracteres hasta encontrar el salto de linea
        printf("Edad: ");
        scanf("%d", &curso[i].edad);                                
        printf("Promedio: ");
        scanf("%f", &curso[i].promedio);
    }

    float promedio_general = calcular_promedio_curso(curso, TAM);   //Aplica la funcion de cal_prom y la asigna en prom_general
    int mejor_estudiante = buscar_mejor_estudiante(curso, TAM);     //Aplica la funcion de buscar_mejor_est y asigna el resultado en mejor_estudiante

    printf("\nPromedio general: %.2f\n", promedio_general);     
    printf("Mejor estudiante: %s con %.2f\n", curso[mejor_estudiante].nombre, curso[mejor_estudiante].promedio);

    return 0;
}
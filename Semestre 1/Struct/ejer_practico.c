#include <stdio.h>

#define TAM 5

struct Estudiantes {
    char nombre[50];
    int edad;
    float promedio;
};

float promedio (struct Estudiantes alumnos[], int n) {
    float suma = 0;
    for (int i = 0; i < n ; i = i+1){
        suma = suma + alumnos[i].promedio;

    }
    return suma/n;
}

int buscar_mejor(struct Estudiantes alumnos[],int n){
    int indice = 0;
    for (int i = 1;i<n;i=i+1){
        if (alumnos [i].promedio > alumnos[indice].promedio) {
            indice = i;
        }
    }
    return indice;
}

int main(){
    struct Estudiantes curso[TAM];

    for (int i = 0; i < TAM; i=i+1){
        printf("Nombre: ");
        scanf(" %[^\n]",curso[i].nombre);

        printf("Edad: ");
        scanf("%d",&curso[i].edad);

        printf("Promedio: ");
        scanf("%f",&curso[i].promedio);
    }
    float promedio_gen = promedio(curso,TAM);
    int mejor_estudiante = buscar_mejor(curso,TAM);

    printf("\nPromedio general: %.2f\n",promedio_gen);
    printf("Mejor Estudiante: %s con %.2f\n", curso[mejor_estudiante].nombre, curso[mejor_estudiante].promedio);

    return(0);



}
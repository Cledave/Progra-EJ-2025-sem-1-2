#include <stdio.h>
struct Estudiante {                 //Crea el struct estudiante que contiene los diferentes tipos de datos
    char nombre[100];
    int edad;
    float nota_1;
    float nota_2;
    float promedio;
};
float calcular_promedios(struct Estudiante alumnos[], int n) {      //Funcion para calcular promedio, tambien calcula el promedio general del curso 
    float suma = 0;                                                 //como la suma total de paso calcula el promedio de cada alumno
    for (int i = 0; i < n; i=i+1) {
        alumnos[i].promedio = (alumnos[i].nota_1 + alumnos[i].nota_2) / 2.0;
        suma += alumnos[i].promedio;
    }                                                               //Es importante que si la funcion no es VOID, 
    return suma / n;                                                //coloquemos el return para saber que es lo que va a asignar al valor final
};
void preguntar_datos(struct Estudiante alumnos[], int n) {          //Funcion para preguntar los datos de cada estudiante
    for (int i = 0; i < n; i++) {
        printf("Nombre del estudiante:  ");
        scanf(" %[^\n]", alumnos[i].nombre);                        //Lee hasta el salto de linea
        printf("Edad del estudiante:  ");
        scanf("%d", &alumnos[i].edad);                              //Pregunta la edad y lo guarda en .edad
        printf("Ingrese nota 1 de %s: ", alumnos[i].nombre);
        scanf("%f", &alumnos[i].nota_1);                            //Ingresa los datos de la nota 1 en .nota_1
            while (alumnos[i].nota_1<1.0||alumnos[i].nota_1>7.0){       //Verifica que los datos de .nota_1 esten entre 1 y 7 
                printf("Nota invalida,Reingrese:    ");
                scanf("%f", &alumnos[i].nota_1);
            }
        printf("Ingrese nota 2 de %s: ", alumnos[i].nombre);
        scanf("%f", &alumnos[i].nota_2);
            while (alumnos[i].nota_2<1.0||alumnos[i].nota_2>7.0){
                printf("Nota invalida,Reingrese:    ");
                scanf("%f", &alumnos[i].nota_2);
            }
            printf("\n");
    }
}
void print_resultados(struct Estudiante alumnos[], int n) {         //Funcion que imprime todos los resultados del struct estudiante
    for (int i = 0; i < n; i++) {
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Nota 1: %.1f\n", alumnos[i].nota_1);
        printf("Nota 2: %.1f\n", alumnos[i].nota_2);
        printf("Promedio: %.2f\n\n", alumnos[i].promedio);
    }
    printf("Promedio general del curso: %.2f\n", calcular_promedios(alumnos, n));
};
int validar_n (int n) {                                             //Sirve para verificar que el valor N (la cantidad de estudiantes), se mantenga dentro de los limites especificos
    while (n <= 0 || n > 10) {
        printf("Valor invalido, mantengase entre 1 y 10.\n");
        printf("Cuantos estudiantes son?: ");
        scanf("%d", &n);
    }
    return n;
};
int buscar_mejor_estudiante(struct Estudiante alumnos[], int n) {   //Busca entre los promedios y guarda su posicion en el indice
    int indice = 0;
    for (int i = 1; i < n; i++) {                                   //Empezamos desde el 1 para asi poder comparar con el 0
        if (alumnos[i].promedio > alumnos[indice].promedio) {       //Si [0] no es mayor que el [1] nada se reemplaza
            indice = i;
        }
    }
    return indice;
};
int main(){
    int n;                                                  //Crea el int que define la cantidad de estudiantes
    printf("Cuantos estudiantes son?: ");   
    scanf("%d", &n);                                        //Escanea la cantidad de estudiantes y lo guarda en N
    n = validar_n(n);                                       //Aplica la funcion de validar N a N
    struct Estudiante alumnos[n];                           //Inicializacion de la Struct
    preguntar_datos(alumnos,n);                             //Aplica la funcion de preguntar datos sobre el struct de estudiantes [alumnos]
    calcular_promedios(alumnos, n);                         //Aplica la funcion de calcular promedio sobre el struct de estudiantes [alumnos] 
    printf("\n\n=====DATOS=====\n");
    print_resultados(alumnos,n);                            //Printea todos los datos almacenados
    int indice = buscar_mejor_estudiante(alumnos, n);       //Asigna el valor de buscar_mejor_alumno
    printf("Mejor estudiante: %s con %.2f\n", alumnos[indice].nombre, alumnos[indice].promedio);    //Print los datos del mejor estudiante
    
return(0);
} 

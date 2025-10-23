//Autor:Claudio Sepulveda
#include <stdio.h>

void ingreso_datos (int *nivel,float *sueldo_b,float *Isa,float *AFP,float *seg_vida);
float bono (int *nivel,float *sueldo_b);
float print_SF (float *Isa,float *AFP,float *seg_vida,float *sueldo_bono,float *sueldo_b);

int main(){

    for (int i=1;i<=8;i=i+1) {
        int nivel = 0;
        float sueldo_b = 0.0;
        float Isa = 0.0;
        float AFP = 0.0;
        float seg_vida = 0.0;
        float sueldo_bono = 0.0;
        float sueldo_final = 0.0;
        ingreso_datos (&nivel,&sueldo_b,&Isa,&AFP,&seg_vida);
        sueldo_bono = bono(&nivel,&sueldo_b);
        sueldo_final = print_SF (&Isa,&AFP,&seg_vida,&sueldo_bono,&sueldo_b);
        printf ("Sueldo Final:%.2f",sueldo_final);
        printf("\n|-----O-----O-----0-----O-----O-----|");
    }
    return 0;
}

/*
Definicion de las funciones
*/

void ingreso_datos (int *nivel,float *sueldo_b,float *Isa,float *AFP,float *seg_vida) {
    printf("\nIngrese nivel de empleado:\t");
        scanf("%d", nivel);
    while (*nivel<0 || *nivel>3){
        printf("\nReingrese.\nNivel: ");
        scanf("%d", nivel);
    }
    printf("Ingrese sueldo base:\t");
        scanf("%f", sueldo_b);
    while (*sueldo_b<0){
        printf("\nReingrese.\nSueldo base: ");
        scanf("%f", sueldo_b);
    }
    *Isa = 0.07*(*sueldo_b);
    *AFP = 0.12*(*sueldo_b);
    if (*nivel == 2 || *nivel == 3 ){
        printf("Se le aplica seguro de vida\n");
        *seg_vida = 0.114*(*sueldo_b);
    }
}

float bono (int *nivel,float *sueldo_b){
    if (*nivel == 0 ){
        return ((*sueldo_b)) + 7000;
    } else if (*nivel == 1 ){
        return (*sueldo_b) + ((*sueldo_b)*0.064);
    } else if (*nivel == 2 ){
        return (*sueldo_b) + ((*sueldo_b)*0.1394);
    } else if (*nivel == 3){
        return (*sueldo_b) + ((*sueldo_b)*0.2194);
    }
}
float print_SF (float *Isa,float *AFP,float *seg_vida,float *sueldo_bono,float *sueldo_b){
    printf("Descuentos:\n");
    printf("Isapre: %.2f\n", *Isa);
    printf("AFP: %.2f\n", *AFP);
    printf("Seguro de vida: %.2f\n",*seg_vida);
    printf("Sumas:\n");
    printf("Bono de nivel:%.2f\n", (*sueldo_bono-(*sueldo_b)));
    float bono_2 = (*sueldo_bono-(*sueldo_b));
        return ((*sueldo_b)-(*Isa)-(*AFP)-(*seg_vida)+(bono_2));
}

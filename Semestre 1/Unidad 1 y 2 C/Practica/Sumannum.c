//Hacer un programa que me sume N cantidad de numeros
#include <stdio.h>
int main (){
    int num_principal=1;
    int suma_a_principal;

    printf("Introducir numeros para sumar\ncoloca 0 para terminar\n");
    while (num_principal!=0) {
        scanf ("%d",&num_principal);
        if (num_principal==0) {
            printf ("Programa terminado\n");
            printf ("El resultado final es %d",suma_a_principal);
        } else {
            suma_a_principal=num_principal+suma_a_principal;
    }
}
}








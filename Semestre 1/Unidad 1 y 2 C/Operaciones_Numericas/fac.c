#include <stdio.h>
/* 
Imprime la table fahrenheit-celsius
para f=0,20,...,300
*/
int main() {
    float f, c;
    int lower, upper, step;

    lower = 0;       //Limite inferior de la tabla de t°
    upper = 10;     // Limite superior
    step = 1;       // Tamaño del incremento
    c = lower;
    printf("Celcius\tFahrenheit\n");
    while (c <= upper) {
        c = (5.0/9.0);
        
        printf("%3.0c\t\t%6.1c\n", c, f);
        
        c = c + step;
    }

    return 0;
}
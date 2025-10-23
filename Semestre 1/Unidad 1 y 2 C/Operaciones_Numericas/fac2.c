#include <stdio.h>

int main() {
    float celsius, fahr;
    int min, max, step;

    min = 0;     
    max = 100;    
    step = 5;      
    
    celsius = min;
    printf("Celcius\tFahrenheit\n");
    while (celsius <= max) {
        fahr = (((9.0 / 5.0) * (celsius))+32);
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
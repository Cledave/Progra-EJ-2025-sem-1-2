//imprime una table que sea de C a fahr
// con encabezado y con saltos de 5 grados
// formula es (C * 9/5)+32
#include <stdio.h>
int main() {
    int low=0;
    int max=100;
    int celsius=0;
    float fahr=0;

    printf("|Celsius  |  fahrenheit  |\n");
        while (celsius<=max) {
            fahr=((9.0/5.0)*celsius)+32;
            printf("|%3.1d    ||°||      %3.1f|\n",celsius,fahr);

            celsius=celsius+5;
        }
return(0);
}
#include <stdio.h>

int main(){
    float pot = 1.0, pi = 0;
    for (int n = 0; n < 100000; n++){
        pi = pi + (pot)/(2*n + 1);
        pot = pot * (-1);
    }
    pi = 4 * pi;
    printf("PI: %f\n", pi);
    return 0;
}
#include <stdio.h>

int main(){
    double pi = 1.0;
    for (int n = 1 ; n < 100000; n++){
        pi = pi * (2*n)/(2*n - 1)*(2*n)/(2*n + 1);
    }
    pi = 2 * pi;
    printf("PI: %lf\n", pi);
    return 0; 
}
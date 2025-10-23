#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Pares
primos
Narcisos
Bi primos
perfectos
*/
void gen_aleat (int min, int max, int count) {
    printf("Random numbers between %d and %d: ", min, max);
    // Loop that will print the count random numbers
    for (int i = 0; i < count; i++) {
        // Find the random number in the range [min, max]
        int rd_num = rand() % (max - min + 1) + min;
        printf("%d ", rd_num);
    }
}

int main() {
    int min = 0;
    int max = 999;
    int count;
    printf("Cuantos numeros?:");
    scanf("%d",&count);
    gen_aleat (min, max, count);
    return 0;
}
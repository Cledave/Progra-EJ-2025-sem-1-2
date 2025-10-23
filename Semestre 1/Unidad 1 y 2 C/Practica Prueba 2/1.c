#include <stdio.h>

int main() {
    int matriz[4][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Elementos de la diagonal principal:\n");

    for (int i = 0; i < 4; i++) {
        printf("matriz[%d][%d] = %d\n", i, i, matriz[i][i]);
    }

    return 0;
}
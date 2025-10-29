#include <stdio.h>

int main() {
    int n, i;
    double pi = 1.0;

    for (i = 1; i <= 50; i++) {
        pi *= (double)(2 * i) / (2 * i - 1) * (2 * i) / (2 * i + 1);
    }
    pi *= 2.0;
    printf("PI %lf\n", pi);
    return 0;
}

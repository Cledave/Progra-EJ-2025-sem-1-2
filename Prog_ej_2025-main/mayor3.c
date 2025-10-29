#include <stdio.h>

int mayor_de_3(int, int, int);

int main(){
    int n1, n2, n3;
    printf("N1: ");
    scanf("%d", &n1);
    printf("N2: ");
    scanf("%d", &n2);
    printf("N3: ");
    scanf("%d", &n3);
    printf("Mayor: %d\n", mayor_de_3(n1, n2, n3));
    return 0;    
}

int mayor_de_3(int n1, int n2, int n3){
    //int mayor = n1;
    int mayor;
    if ((n1 >= n2) && (n1 >= n3)){
        mayor = n1;
    }
    if ((n2 >= n1) && (n2 >= n3)){
        mayor = n2;
    }
    if ((n3 >= n1) && (n3 >= n2)){
        mayor = n3;
    }
    return mayor;
}

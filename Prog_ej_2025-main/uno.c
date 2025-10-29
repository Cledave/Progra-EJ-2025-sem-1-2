#include <stdio.h>

int main ( ) {
    int prim, seg, resul;
    char oper;
    printf ( "\nPrimer numero: " ) ;
    scanf("%d", &prim);
    printf("\nOperacion a realizar (+,-,*,/): ");
    scanf(" %c", &oper);
    printf("\nSegundo numero: ");
    scanf("%d", &seg);
    if(oper == '+' ) {
        resul = prim + seg ;
    }
    if(oper == '-' ) {
        resul=prim-seg;
    }
    if(oper == '*' ) {
        resul = prim * seg ;
    }
    if(oper == '/' ) {
        resul = prim / seg ;
    }   
    printf ("\n El resultado de la operacion \n-o" ) ;
    printf("%d %c %d es %d\n", prim, oper, seg, resul);
    return 0;
}

//Autor:Claudio Sepulveda
#include <stdio.h>

int fib(int);

//Fibbonacii
int main(){
    int n;
    printf("N?\n");
    scanf("%d",&n);
    int fibonacci = fib(n);
    printf("Fibbonaci: %d", fibonacci);

}


/* 
Definciones
*/

int fib (int n){
    if ((n==1)||(n==2)){
        return 1;
    }
    else{
        return (fib(n-1))+(fib(n-2));
    }
}
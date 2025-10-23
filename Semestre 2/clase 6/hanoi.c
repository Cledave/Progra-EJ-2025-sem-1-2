#include <stdio.h>

void hanoi(int n,int com, int aux, int fin);

int contador = 0;

//Hanoi

int main(){
    int n = 5,com = 1,aux = 2,fin = 3;
    hanoi(n,com,aux,fin);
    return 0;

}

void hanoi(int n,int com, int aux, int fin){
    if(n==1)
        printf("%d -> %d",com,fin);
    else{   
        hanoi(n-1,com,fin,aux);
        printf("\n%d -> %d\n",com,fin);
        hanoi(n-1,aux,com,fin);
    }
}
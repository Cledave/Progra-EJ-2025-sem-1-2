#include <stdio.h>
/*
Hacer un programa que genera triangulos de acuerdo al pedido del usuario
5
*
**
***
****
*****
*/
int main(){
    int num;
    char ast = '*';
    printf("De cuantos *?:\n");
    scanf("%d",&num);
    printf("\n");
    for (int a=1;a<=num;a=a+1){
        for (int b=1;b<=a;b=b+1){ 
            printf("%c",ast);
        }
        printf("\n");
    }
}


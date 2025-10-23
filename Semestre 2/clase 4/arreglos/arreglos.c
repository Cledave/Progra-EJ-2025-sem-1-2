#include <stdio.h>

int main(){
    int n[10];

    for (int i=1;i<=10;i++){
        n[i] = i;
    }
    for (int i=1;i<=10;i=i+1){
        printf("%d",n[i]);
        if (i==5){
            printf("\n");
        }
    }


}
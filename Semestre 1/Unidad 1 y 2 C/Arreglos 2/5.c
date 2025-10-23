#include <stdio.h>
#include <string.h>
int main(){
    char frase1[20];
    char frase2[20];

    printf("Ingrese una frase: ");                      
        scanf("%s",frase1);

    int b=strlen(frase1);
    frase2[b] = '\0';
    for (int a=0; a<=strlen(frase1);a=a+1){
        frase2[a]=frase1[b-a-1];
    }
    for (int c=0;c<b;c=c+1){
        if (frase1[c]!=frase2[c]){
            printf("No es palindromo");
            return(0);
        } else {
            printf("Palindromo");
            return(0);
        }
    }
    }

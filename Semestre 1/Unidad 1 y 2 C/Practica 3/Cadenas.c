#include <stdio.h>
#include <ctype.h>

int main () {
    char C[] = {'H','o','l','a','\n','M','u','n','d','o','\0'};
    printf("%c,%c\n",C[1],C[5]);
    printf("%s",C);
}
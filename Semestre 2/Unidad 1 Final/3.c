#include <stdio.h>

int main(){
    int  *p1;
    int p1;
    p1 = 1;
    *p1 = 2;
    printf("%d %d %d\n", p1,*p1);
    return 0;
}
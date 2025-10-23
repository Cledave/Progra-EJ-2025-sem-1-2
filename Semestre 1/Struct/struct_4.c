#include <stdio.h>

struct persona {
    char nombre[30];
    int edad;
};

void cambiaredad(struct persona*p,int nuevaedad){
    p->edad=nuevaedad;
}

int main(){
    struct persona p1 = {"jorge", 25};

    cambiaredad(&p1, 30);
    printf("Nombre:%s\nEdad actualizada: %d\n",p1.nombre,p1.edad);

    return(0);


}
    

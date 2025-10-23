#include <stdio.h>                                          //Libreria basica de C
#define _USE_MATH_DEFINES
#include <math.h>                                           //Libreria basica para operacion matematicas
#include <string.h>                                         //Sirve para crear y almacenar strings, ademas de diversas funciones para leer e usarlas
#include "tinyexpr.h"                                       //importa una libreria externa que permite evaluar expresiones matematicas escritas
#include <stdlib.h>                                         //Funciones estandar de C

#define RAD_TO_DEG (180.0/M_PI)                                                            // convierte radianes a grados
#define DEG_TO_RAD (M_PI/180.0)                                                            // grados a radianes


float leer_expresion(const char *mensaje, int puede_ser_cero) {
    char input[100];        // Cadena para guardar la expresión ingresada por el usuario
    float resultado;        // Resultado de evaluar la expresión
    int valido = 0;         // para ver si la entrada es válida

    while (!valido) {           // Repite hasta que se reciba una entrada válida
        printf("%s", mensaje);
        scanf(" %[^\n]%*c", input);  // Lee toda la línea, incluyendo espacios y expresiones

        int error;
        resultado = te_interp(input, &error);       // Usa tinyexpr para evaluar la expresion

        if (error) {
            printf("Expresion invalida. Intenta de nuevo.\n");      //Error de sintaxis
        } else if (!puede_ser_cero && resultado == 0.0f) {
            printf("Este valor no puede ser 0. Reintenta.\n");      //Para ocasiones en las que no pueda ser cero
        } else if (resultado < 0 && puede_ser_cero == 2) {
            printf("Este valor no puede ser negativo. Reintenta.\n");   //Para cuando no pueda ser <0
        } else {
            valido = 1;     //para cuando sea valido
        }
    }
/*  Pide al usuario una expresión matemática como 2*sqrt(3).
    La evalúa con la función te_interp() de TinyExpr. 
    Valida el resultado, dependiendo del valor de puede_ser_cero:
    0 → no se permite cero.
    1 → se permite cualquier número.
    2 → no se permite negativo.                                         */

    return resultado;
}


int main(){                                                                                 //Se inicia el programa
    int valid;
    int opcion;
    printf("\n========= Menu =========\n");                                                 // Se muestra el menu del programa en el que elegir lo que haremos a coninuacion
    printf("1. Resolver Cuadratica\n");
    printf("2. Resolver Triangulo\n");
    printf("3. Finalizar programa\n");
    printf("Seleccione una opcion: ");
    valid = scanf("%d", &opcion);                                                           //Sirve para validar que sea un input correcto de int 
            while (valid != 1 || opcion > 3 || opcion < 1){
                printf("Opcion invalida\nreingrese:\t");
                while (getchar() != '\n');
                valid = scanf("%d",&opcion);
            }     

    if (opcion == 1) {                                                    
                                                                                            //Crea los 3 floats que son A,B Y C de la cuadratica
    float a = leer_expresion("Ingresa A: ", 0);                                             //EJEMPLO DEL USO DE TINYEXPR, el mensaje es "ingresa a" y el int 
    float b = leer_expresion("Ingresa B: ", 1);                                             //denominado como "puede ser cero" es 0,1 o 2, dependiendo del caso        
    float c = leer_expresion("Ingresa C: ", 1);
        
        float discriminante = (b*b)-4*a*c;                                                  //Define la formula para el discriminante
        if (discriminante>0){                                                               //Decide el primer caso
            float cuadratica_1 = (-b + sqrt(discriminante))/(2*a);                          //Primera solucion de la formula cuadratica con el + (sqrt es raiz cuadrada, es biblioteca de math.h)
            float cuadratica_2 = (-b - sqrt(discriminante))/(2*a);                          //segunda solucion de la formula cuadratica con el -
            float suma_sol = (cuadratica_1 + cuadratica_2);                                 //Suma de las soluciones        
            float producto_sol = (cuadratica_1 * cuadratica_2);                             //Producto de ambas soluciones
            printf("El descriminantes es %.2f",discriminante);
            printf("2 soluciones reales positivas:\n");
            printf("Solucion 1:                 %.2f\n",cuadratica_1);
            printf("Solucion 2:                 %.2f\n",cuadratica_2);                      //Se encagar de printear cada solucion disponible
            printf("Suma de las soluciones:     %.2f\n",suma_sol);
            printf("Producto de las soluciones: %.2f",producto_sol);

        } else if (discriminante==0) {                                                      //Segundo caso cuando el discriminante es 0
            float cuadratica_1 = (-b + sqrt(discriminante))/(2*a);                          // la unica solucion
            float suma_sol = (cuadratica_1 * 2);                                            //Suma de la solucion
            float producto_sol = (cuadratica_1 * cuadratica_1);                             //Producto de la solucion
            printf("\nEl discriminante es cero.\n");
            printf("La ecuacion es lineal\n");
            printf("Una unica solucion real doble:\t%.2f\n",cuadratica_1);
            printf("Suma de las soluciones:     %.2f\n",suma_sol);                          //Printea los resultados
            printf("Producto de las soluciones: %.2f",producto_sol);

        } else if (discriminante<0) {
            printf("El discriminantes es %.2f\n",discriminante);
            printf("No soluciones en los reales, discriminante menor a 0, dos soluciones complejas");                //En el caso 3 descarta todo y simplimente dice que no existen soluciones en los reales
        }
        return(0);

    //EMPIEZA TRIANGULOS

    } else if (opcion == 2) {                                              //decide si es un triangulo
   
printf("\n");
printf("                   b\n");
printf("                  /|\\\n");
printf("                 / | \\\n");
printf("             A  /  |  \\  C\n");                                    //Imprime un triangulo para demostracion del ingreso de valores
printf("               /   |   \\\n");
printf("              /    |    \\\n");
printf("             /     |     \\\n");
printf("            /      |      \\\n");
printf("         y /_______|_______\\ a\n");
printf("                   B         \n");

    
        
        int valid;
        int cont_ang = 3; float ang_Alpha; float ang_Beta; float ang_Gamma;                                   //Inicia un contador de angulos y los inicio como float
        int cont_lado = 3; float lado_A; float lado_B; float lado_C;                                          //Inicia un contador de lados y los inicia como float

    printf("Ingresa Lados, si es desconocido un 0:\n");      

// Lectura de lados
lado_A = leer_expresion("Lado A: ", 2);
lado_B = leer_expresion("Lado B: ", 2);
lado_C = leer_expresion("Lado C: ", 2);

// Ajuste del contador de lados
if (lado_A == 0) cont_lado--;
if (lado_B == 0) cont_lado--;
if (lado_C == 0) cont_lado--;

printf("\nIngresa Angulos,en grados, si es desconocido un 0:\n");

ang_Alpha = leer_expresion("Angulo Alpha: ", 1);
if (ang_Alpha == 0) cont_ang--;
else if (ang_Alpha < 0 || ang_Alpha > 180) {
    printf("Angulo invalido. Reingrese.\n");
    ang_Alpha = leer_expresion("Angulo Alpha: ", 1);
}

ang_Beta = leer_expresion("Angulo Beta: ", 1);
if (ang_Beta == 0) cont_ang--;
else if (ang_Beta < 0 || ang_Beta > 180) {
    printf("Angulo invalido. Reingrese.\n");
    ang_Beta = leer_expresion("Angulo Beta: ", 1);
}
            
ang_Gamma = leer_expresion("Angulo Gamma: ", 1);
if (ang_Gamma == 0) cont_ang--;
else if (ang_Gamma < 0 || ang_Gamma > 180) {
    printf("Angulo invalido. Reingrese.\n");
    ang_Gamma = leer_expresion("Angulo Gamma: ", 1);
}


    if  ((ang_Alpha > 0 && ang_Beta > 0 && ang_Alpha + ang_Beta >= 180.0f) || 
       (ang_Alpha > 0 && ang_Gamma > 0 && ang_Alpha + ang_Gamma >= 180.0f) || 
        (ang_Beta > 0 && ang_Gamma > 0 && ang_Beta + ang_Gamma >= 180.0f)) {
        printf("\nSuma de los angulos superior a 180, reingrese.\n");
        return 0;                                                                           //Sirve para comprobar si la suma de los angulos en diferentes casos es mayor a 180
    }                                                                                      

//CASO 1 LLL
    if (cont_lado==3 && cont_ang==0) {                                                                          //Si se ingresan los 3 lados y no angulos, se usa el teorema del coseno para calcular los angulos
        if ((lado_A + lado_B <= lado_C) || (lado_B + lado_C <= lado_A) || (lado_C + lado_A <= lado_B)) {
            printf("\nNo se cumple la desigualdad triangular,reingrese.\n");                                    //Comprueba la desigualdad triangular, si no se cumple termina el 
            return 0;                                                                                           //programa
        }                                                                                                       //Primer caso, cuando se me dan los 3 lados
        ang_Alpha = (acos((lado_B*lado_B+lado_C*lado_C-lado_A*lado_A)/(2*lado_B*lado_C))*RAD_TO_DEG);                                                                   
        ang_Beta = (acos((lado_A*lado_A+lado_C*lado_C-lado_B*lado_B)/(2*lado_A*lado_C))*RAD_TO_DEG);   //Aplica formula del coseno despejada en cada caso
        ang_Gamma = (acos((lado_A*lado_A+lado_B*lado_B-lado_C*lado_C)/(2*lado_A*lado_B))*RAD_TO_DEG);   //El RAD_TO_DEG esta definido al inicio, es una conversion basico de radeones a grados
    }

//CASO 2 LAL  
// sirve para a + b + gamma
// sirve para b + c + alpha
// sirve para c + a + beta

    else if (cont_lado==2 && cont_ang==1) {                                   
        if (lado_A>0 && lado_B>0 && ang_Gamma>0) {
            lado_C = (sqrtf((lado_A*lado_A+lado_B*lado_B)-2*lado_A*lado_B*cos(ang_Gamma*DEG_TO_RAD)));   
            ang_Alpha = (asin((sin(ang_Gamma*DEG_TO_RAD)*lado_A)/lado_C))*RAD_TO_DEG;                 
            ang_Beta  = 180.0f - ang_Alpha - ang_Gamma;                                                     
        }
        else if (lado_B>0 && lado_C>0 && ang_Alpha>0) {
            lado_A = (sqrtf((lado_B*lado_B+lado_C*lado_C)-2*lado_B*lado_C*cos(ang_Alpha*DEG_TO_RAD)));      //Usa mezcla del teorema de seno + teorema de coseno para conseguir los resultados
            ang_Beta = (asin((sin(ang_Alpha*DEG_TO_RAD)*lado_B)/lado_A))*RAD_TO_DEG;                        //tengo que transformar a deg to rad, porque las funciones dee C esperan recibir rad
            ang_Gamma = 180.0f - ang_Alpha - ang_Beta;                                                      //Aunque despues las devuelvo a deg
        }
        else if (lado_C>0 && lado_A>0 && ang_Beta>0) {
            lado_B = (sqrtf((lado_C*lado_C+lado_A*lado_A)-2*lado_A*lado_C*cos(ang_Beta*DEG_TO_RAD)));
            ang_Gamma = (asin((sin(ang_Beta*DEG_TO_RAD)*lado_C)/lado_B))*RAD_TO_DEG;
            ang_Alpha = 180.0f - ang_Beta - ang_Gamma;
        } else {
            printf("Invalido.\n");
            return 0;
        }
    }

//CASO 3 AAL

    else if (cont_ang==2 && cont_lado==1) {
        if (ang_Alpha==0) {
            ang_Alpha = 180.0f - ang_Beta - ang_Gamma;
        }
        else if (ang_Beta==0) {
            ang_Beta = 180.0f - ang_Alpha - ang_Gamma;                                                  //consigue el tercer angulo faltante
        }
        else if (ang_Gamma==0) {
            ang_Gamma = 180.0f - ang_Alpha - ang_Beta;
        }

        if (lado_A>0) {
            lado_B = lado_A * sinf(ang_Beta*DEG_TO_RAD) / sinf(ang_Alpha*DEG_TO_RAD);
            lado_C = lado_A * sinf(ang_Gamma*DEG_TO_RAD) / sinf(ang_Alpha*DEG_TO_RAD);
        }
        else if (lado_B>0) {
            lado_A = lado_B * sinf(ang_Alpha*DEG_TO_RAD) / sinf(ang_Beta*DEG_TO_RAD);                           //Usa ley del seno con el lado existente, para obtener el resto de lados 
            lado_C = lado_B * sinf(ang_Gamma*DEG_TO_RAD) / sinf(ang_Beta*DEG_TO_RAD);
        }
        else if (lado_C>0) {
            lado_A = lado_C * sinf(ang_Alpha*DEG_TO_RAD) / sinf(ang_Gamma*DEG_TO_RAD);
            lado_B = lado_C * sinf(ang_Beta*DEG_TO_RAD) / sinf(ang_Gamma*DEG_TO_RAD);
        }
    } else {
        printf("\nNo se cumplen las condiciones para resolver el triangulo. Por favor ingresar en los siguientes formatos:\n");
        printf("1. Tres Lados\n");
        printf("2. Dos lados y el angulo que forman\n");
        printf("3. Un lado y los angulos adyacentes\n");                                   //Enumera todos los casos posibles para los que esta preparado el programa                                                                           //Si no se cumple ningun caso, termina el programa
        return(0);
    }

    printf("\n--- Resultados del triangulo ---\n");
    printf("Lado A:         %.2f\n", lado_A);
    printf("Lado B:         %.2f\n", lado_B);
    printf("Lado C:         %.2f\n", lado_C);                                               //Imprime todos los datos disponibles
    printf("Angulo Alpha:   %.2f\n", ang_Alpha);
    printf("Angulo Beta:    %.2f\n", ang_Beta);
    printf("Angulo Gamma:   %.2f\n", ang_Gamma);

} else if (opcion == 3) {
    printf("Programa finalizado.\n");
    return(0);
}
}
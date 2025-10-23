#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#define RAD_TO_DEG (180.0/3.1415)                                                            // convierte radianes a grados
#define DEG_TO_RAD (3.1415/180.0)                                                            // grados a radianes

//para cuadratica
float leer_valor(char nombre) {
    char input[100];
    float valor = 0;
    int valido = 0;

    while (!valido) {
        printf("Ingresa %c: ", nombre);
        scanf("%s", input);

        // Si comienza con sqrt( y termina con )
        if (strncmp(input, "sqrt(", 5) == 0 && input[strlen(input) - 1] == ')') {
            char numero_str[90];
            strncpy(numero_str, input + 5, strlen(input) - 6); // copia lo que está entre paréntesis
            numero_str[strlen(input) - 6] = '\0'; // asegura el final de cadena

            float num;
            if (sscanf(numero_str, "%f", &num) == 1 && num >= 0) {
                valor = sqrt(num);
                valido = 1;
            } else {
                printf("Raíz inválida o negativa. Intenta de nuevo.\n");
            }
        }
        // Si es un número normal
        else if (sscanf(input, "%f", &valor) == 1) {
            valido = 1;
        } else {
            printf("Entrada inválida. Intenta de nuevo.\n");
        }

        // En el caso de A, no puede ser cero
        if (nombre == 'A' && valor == 0) {
            printf("A no puede ser 0. Reingresa.\n");
            valido = 0;
        }
    }

    return valor;
}
//para triangulos
float leer_lado(char nombre, int *contador) {
    char input[100];
    float valor = 0;
    int valido = 0;

    while (!valido) {
        printf("Lado %c:   ", nombre);
        scanf("%s", input);

        // Detecta "sqrt(...)"
        if (strncmp(input, "sqrt(", 5) == 0 && input[strlen(input) - 1] == ')') {
            char numero_str[90];
            strncpy(numero_str, input + 5, strlen(input) - 6);
            numero_str[strlen(input) - 6] = '\0';

            float num;
            if (sscanf(numero_str, "%f", &num) == 1 && num >= 0) {
                valor = sqrt(num);
                valido = 1;
            } else {
                printf("Raíz inválida o negativa. Intenta de nuevo.\n");
            }
        }
        // Si es número directo
        else if (sscanf(input, "%f", &valor) == 1) {
            valido = 1;
        } else {
            printf("Entrada inválida. Intenta de nuevo.\n");
        }

        if (valido && valor < 0) {
            printf("Lado inválido (no puede ser negativo). Intenta de nuevo.\n");
            valido = 0;
        }
    }
    // Ajusta el contador si es 0
    if (valor == 0) {
        (*contador)--;
    }
    return valor;
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
        int valid;
        //float a;float b;float c;                                                            //Crea los 3 floats que son A,B Y C de la cuadratica

    float a = leer_valor('A');
    float b = leer_valor('B');
    float c = leer_valor('C');
        
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
printf("                   y\n");
printf("                  /|\\\n");
printf("                 / | \\\n");
printf("             A  /  |  \\  C\n");
printf("               /   |   \\\n");
printf("              /    |    \\\n");
printf("             /     |     \\\n");
printf("            /      |      \\\n");
printf("         a /_______|_______\\ b\n");
printf("                   B         \n");

             //α β γ        
        
        int valid;
        int cont_ang = 3; float ang_Alpha; float ang_Beta; float ang_Gamma;                //Inicia un contador de angulos y los inicio como float
        int cont_lado = 3; float lado_A; float lado_B; float lado_C;                                          //Inicia un contador de lados y los inicia como float

    printf("Ingresa Lados, si es desconocido un 0:\n");      

    lado_A = leer_lado('A', &cont_lado);
    lado_B = leer_lado('B', &cont_lado);
    lado_C = leer_lado('C', &cont_lado);

        printf("\nIngresa Angulos,en grados, si es desconocido un 0:\n");
        printf("Angulo Alpha: ");
        valid = scanf("%f",&ang_Alpha);
            if (ang_Alpha==0){
                cont_ang = cont_ang - 1;                                                                    //Pregunta por los angulos y comprueba que no sea menores a 0
            } else if (ang_Alpha<0 || ang_Alpha>180){                                                                        //ademas va registrando cuantos existen con el contador
                printf("Angulo invalido, reingrese Angulo Alpha:\t\n");
                scanf("%f",&ang_Alpha);
            }  while (valid != 1){                                                                          // otra vez usamos valid para comprabar que sea un input correcto
                printf("Valor Invalido\nreingrese Angulo Alpha:\t");
                while (getchar() != '\n');
                valid = scanf("%f",&ang_Alpha);
            }
        printf("Angulo Beta: ");
        valid = scanf("%f",&ang_Beta);
            if (ang_Beta==0){
                cont_ang = cont_ang - 1;
            } else if (ang_Beta<0 || ang_Beta>180){
                printf("Angulo invalido, reingrese Angulo Beta:\t\n");
                scanf("%f",&ang_Beta);
            }  while (valid != 1){
                printf("Valor Invalido\nreingrese Angulo Beta:\t");
                while (getchar() != '\n');
                valid = scanf("%f",&ang_Beta);
            }
        printf("Angulo Gamma: ");
        scanf("%f",&ang_Gamma);
            if (ang_Gamma==0){
                cont_ang = cont_ang - 1;
            } else if (ang_Gamma<0 || ang_Gamma>180){
                printf("Angulo invalido, reingrese Angulo Gamma:\t\n");
                scanf("%f",&ang_Gamma);
            }  while (valid != 1){
                printf("Valor Invalido\nreingrese Angulo Gamma:\t");
                while (getchar() != '\n');
                valid = scanf("%f",&ang_Gamma);
            }

    if ((ang_Alpha > 0 && ang_Beta > 0 && ang_Alpha + ang_Beta >= 180.0f) || (ang_Alpha > 0 && ang_Gamma > 0 && ang_Alpha + ang_Gamma >= 180.0f) || (ang_Beta > 0 && ang_Gamma > 0 && ang_Beta + ang_Gamma >= 180.0f)) {
        printf("\nSuma de los angulos superior a 180, reingrese.\n");
        return 0;                                                                           //Sirve para comprobar si la suma de los angulos en diferentes casos es mayor a 180
    }                                                                                      

//CASO 1 LLL
    if (cont_lado==3 && cont_ang==0) {                                                       //Si se ingresan los 3 lados y no angulos, se usa el teorema del coseno para calcular los angulos
        if ((lado_A + lado_B <= lado_C) || (lado_B + lado_C <= lado_A) || (lado_C + lado_A <= lado_B)) {
            printf("\nNo se cumple la desigualdad triangular,reingrese.\n");                                    //Comprueba la desigualdad triangular, si no se cumple termina el 
            return 0;                                                                                           //programa
        }                                                                                                       //Primer caso, cuando se me dan los 3 lados
        ang_Alpha = (acos((lado_B*lado_B+lado_C*lado_C-lado_A*lado_A)/(2*lado_B*lado_C))*RAD_TO_DEG);                                                                   
        ang_Beta = (acos((lado_A*lado_A+lado_C*lado_C-lado_B*lado_B)/(2*lado_A*lado_C))*RAD_TO_DEG);   //aplica formula del coseno despejada en cada caso
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
            ang_Beta = 180.0f - ang_Alpha - ang_Gamma;                      //consigue el tercer angulo faltante
        }
        else if (ang_Gamma==0) {
            ang_Gamma = 180.0f - ang_Alpha - ang_Beta;
        }

        if (lado_A>0) {
            lado_B = lado_A * sinf(ang_Beta*DEG_TO_RAD) / sinf(ang_Alpha*DEG_TO_RAD);
            lado_C = lado_A * sinf(ang_Gamma*DEG_TO_RAD) / sinf(ang_Alpha*DEG_TO_RAD);
        }
        else if (lado_B>0) {
            lado_A = lado_B * sinf(ang_Alpha*DEG_TO_RAD) / sinf(ang_Beta*DEG_TO_RAD);       //Usa ley del seno con el lado existente, para obtener el resto de lados 
            lado_C = lado_B * sinf(ang_Gamma*DEG_TO_RAD) / sinf(ang_Beta*DEG_TO_RAD);
        }
        else if (lado_C>0) {
            lado_A = lado_C * sinf(ang_Alpha*DEG_TO_RAD) / sinf(ang_Gamma*DEG_TO_RAD);
            lado_B = lado_C * sinf(ang_Beta*DEG_TO_RAD) / sinf(ang_Gamma*DEG_TO_RAD);
        }
    } else {
        printf("\nNo se cumplen las condiciones para resolver el triangulo. Por favor ingresar en los siguientes formatos:\n");
        printf("1. Lado A, Lado B, Lado C\n");
        printf("2. Lado A, Lado B, Angulo Gamma\n");
        printf("3. Lado B, Lado C, Angulo Alpha\n");
        printf("4. Lado C, Lado A, Angulo Beta\n");
        printf("5. Lado A, Angulo Beta, Angulo Gamma\n");
        printf("5. Lado B, Angulo Alpha, Angulo Gamma\n");
        printf("5. Lado C, Angulo Alpha, Angulo Beta\n");
        printf("6. Lado A, Lado B, Angulo Alpha\n");

        return 0;                                                                           //Si no se cumple ningun caso, termina el programa
    }

    printf("\n--- Resultados del triangulo ---\n");
    printf("Lado A:         %.2f\n", lado_A);
    printf("Lado B:         %.2f\n", lado_B);
    printf("Lado C:         %.2f\n", lado_C);
    printf("Angulo Alpha:   %.2f\n", ang_Alpha);
    printf("Angulo Beta:    %.2f\n", ang_Beta);
    printf("Angulo Gamma:   %.2f\n", ang_Gamma);

} else if (opcion == 3) {
    printf("Programa finalizado.\n");
    return(0);
}
}
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Función para convertir grados a radianes
double rad(double grados) {
    return grados * PI / 180.0;
}

// Función para convertir radianes a grados
double deg(double radianes) {
    return radianes * 180.0 / PI;
}

// Función principal para resolver triángulos
void resolverTriangulo() {
    double a = 0, b = 0, c = 0; // Lados
    double A = 0, B = 0, C = 0; // Ángulos

    // Entrada de datos
    printf("\nIngresa los lados conocidos (usa 0 si no lo sabes):\n");
    printf("Lado a: "); scanf("%lf", &a);
    printf("Lado b: "); scanf("%lf", &b);
    printf("Lado c: "); scanf("%lf", &c);

    printf("Ingresa los ángulos conocidos en grados (usa 0 si no lo sabes):\n");
    printf("Ángulo A: "); scanf("%lf", &A);
    printf("Ángulo B: "); scanf("%lf", &B);
    printf("Ángulo C: "); scanf("%lf", &C);

    // Validación de datos
    if (a < 0 || b < 0 || c < 0 || A < 0 || B < 0 || C < 0) {
        printf("Error: No se permiten valores negativos.\n");
        return;
    }

    if ((A > 0 && B > 0 && A + B >= 180) || 
        (A > 0 && C > 0 && A + C >= 180) || 
        (B > 0 && C > 0 && B + C >= 180)) {
        printf("Error: La suma de los ángulos no puede ser mayor o igual a 180°.\n");
        return;
    }

    // CASO LLL: tres lados conocidos
    if (a > 0 && b > 0 && c > 0) {
        if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
            printf("Error: No se cumple la desigualdad triangular.\n");
            return;
        }

        // Teorema del Coseno para hallar el ángulo C
        C = acos((a*a + b*b - c*c) / (2 * a * b));
        C = deg(C); // Convertimos a grados

        // Teorema del Seno para hallar ángulo A
        A = deg(asin((a * sin(rad(C))) / c));
        B = 180 - A - C;
    }

    // CASO LAL: dos lados y ángulo entre ellos
    else if (a > 0 && b > 0 && C > 0) {
        double C_rad = rad(C);
        c = sqrt(a*a + b*b - 2*a*b*cos(C_rad)); // Teorema del coseno
        A = deg(asin((a * sin(C_rad)) / c));    // Teorema del seno
        B = 180 - A - C;
    }

    // CASO AAL o ALA: dos ángulos y un lado
    else if (A > 0 && B > 0 && c > 0) {
        C = 180 - A - B; // Suma de ángulos internos
        a = (c * sin(rad(A))) / sin(rad(C));
        b = (c * sin(rad(B))) / sin(rad(C));
    }

    // Mostrar resultados si algún caso se resolvió
    if ((A > 0 && B > 0 && C > 0) && (a > 0 && b > 0 && c > 0)) {
        printf("\n--- Resultados del triángulo ---\n");
        printf("Lados:\n");
        printf("a = %.2lf\n", a);
        printf("b = %.2lf\n", b);
        printf("c = %.2lf\n", c);
        printf("Ángulos:\n");
        printf("A = %.2lf°\n", A);
        printf("B = %.2lf°\n", B);
        printf("C = %.2lf°\n", C);
    } else {
        printf("No se pudo resolver el triángulo con los datos proporcionados.\n");
    }
}

// Función principal
int main() {
    int opcion;
    do {
        printf("\n=== Menú ===\n");
        printf("1. Resolver triángulo\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                resolverTriangulo();
                break;
            case 0:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}

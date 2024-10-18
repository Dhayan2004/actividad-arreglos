#include <stdio.h>

#define CANTIDAD_ALIMENTOS 4

int main() {
    // Arreglos para alimentos, precios y cantidades
    char *alimentos[CANTIDAD_ALIMENTOS] = {"Hamburguesa", "Pizza", "Tacos", "Refrescos"};
    float precios[CANTIDAD_ALIMENTOS] = {50.00, 80.00, 25.00, 20.00};
    int cantidad[CANTIDAD_ALIMENTOS] = {0};  // Inicializamos las cantidades a 0
    
    char continuar;
    int opcion;
    int cantidadIngresada;
    
    // Menu
    printf("Bienvenido al restaurante SM41:\n");
    printf("Menu\n");
    for (int i = 0; i < CANTIDAD_ALIMENTOS; i++) {
        printf("%d - %s - $%.2f\n", i + 1, alimentos[i], precios[i]);
    }
    printf("5 - Salir\n");

    do {
        printf("Ingresa una opcion: ");
        scanf("%d", &opcion);

        // Validar que la opción esté entre las permitidas
        if (opcion >= 1 && opcion <= CANTIDAD_ALIMENTOS) {
            printf("Ingresa la cantidad de %s: ", alimentos[opcion - 1]);
            scanf("%d", &cantidadIngresada);
            
            // Sumar la cantidad ingresada a la que ya estaba
            cantidad[opcion - 1] += cantidadIngresada;
        } else if (opcion != 5) {
            printf("Opcion invalida. Intenta de nuevo.\n");
        }

        if (opcion != 5) {
            printf("¿Deseas hacer otro pedido? (s/n): ");
            scanf(" %c", &continuar);  // 
        } else {
            continuar = 'n';  // 
        }
        
    } while (continuar == 's');
    
    printf("\nResumen de cuenta:\n");
    float totalGeneral = 0.0;
    for (int i = 0; i < CANTIDAD_ALIMENTOS; i++) {
        if (cantidad[i] > 0) {
            float totalPorAlimento = precios[i] * cantidad[i];
            printf("%s - $%.2f x %d = $%.2f\n", alimentos[i], precios[i], cantidad[i], totalPorAlimento);
            totalGeneral += totalPorAlimento;
        }
    }

    printf("\nTotal general a pagar: $%.2f\n", totalGeneral);

    return 0;
}
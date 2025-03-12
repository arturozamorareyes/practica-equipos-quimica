#include <stdio.h>
#include <stdlib.h>

// Función para comparar dos enteros (para qsort)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    // Pedir número de jugadores
    printf("Cuantos jugadores son (debe ser numero par): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Debe ser un numero par de jugadores.\n");
        return 0;
    }

    int skill[n];
    int totalSum = 0;

    // Leer habilidades
    printf("Ingresa las habilidades de los jugadores:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &skill[i]);
        totalSum += skill[i];
    }

    int numTeams = n / 2;

    // Si no se puede dividir equitativamente
    if (totalSum % numTeams != 0) {
        printf("-1\n");
        return 0;
    }

    int targetSum = totalSum / numTeams;

    // Ordenar arreglo
    qsort(skill, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int totalChemistry = 0;

    // Emparejar extremos
    while (left < right) {
        if (skill[left] + skill[right] != targetSum) {
            printf("-1\n");
            return 0;
        }

        totalChemistry += skill[left] * skill[right];
        left++;
        right--;
    }

    printf("Quimica total: %d\n", totalChemistry);
    return 0;
}
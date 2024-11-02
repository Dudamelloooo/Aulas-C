// considerando que uma matriz identidade é uma matriz qubrada que tem 1 na diagonal principal e 0 nos demais elementos, faça um prgrama que crie e exiba uma matriz identidade de ordem 5. (5x5)

#include <stdio.h>

int main() {
    int matriz[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    printf("Matriz Identidade 5x5:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

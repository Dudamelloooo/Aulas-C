#include <stdio.h>

#define SIZE 3

int main() {
    int matriz[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int numero, encontrado = 0;

    printf("Digite o número a ser procurado: ");
    scanf("%d", &numero);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matriz[i][j] == numero) {
                printf("Número encontrado na posição [%d][%d]\n", i, j);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("Número não encontrado na matriz.\n");
    }

    return 0;
}

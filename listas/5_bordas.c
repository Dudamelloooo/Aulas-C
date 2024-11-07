#include <stdio.h>

#define SIZE 4

void lerMatriz(int matriz[SIZE][SIZE]) {
    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int somaBordas(int matriz[SIZE][SIZE]) {
    int soma = 0;
    for (int i = 0; i < SIZE; i++) {
        soma += matriz[0][i];
        soma += matriz[SIZE - 1][i];
    }
    for (int i = 1; i < SIZE - 1; i++) {
        soma += matriz[i][0];
        soma += matriz[i][SIZE - 1];
    }
    return soma;
}

int main() {
    int matriz[SIZE][SIZE];
    lerMatriz(matriz);
    int soma = somaBordas(matriz);
    printf("A soma dos elementos das bordas é: %d\n", soma);
    return 0;
}

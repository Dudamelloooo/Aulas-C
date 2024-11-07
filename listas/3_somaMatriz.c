#include <stdio.h>

#define SIZE 2

void lerMatriz(int matriz[SIZE][SIZE], const char *nome) {
    printf("Digite os elementos da matriz %s:\n", nome);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &matriz[i][j]);
}

void somaMatrizes(int matriz1[SIZE][SIZE], int matriz2[SIZE][SIZE], int resultado[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
}

void exibirMatriz(int matriz[SIZE][SIZE]) {
    printf("Matriz resultante da soma:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int main() {
    int matriz1[SIZE][SIZE], matriz2[SIZE][SIZE], matrizSoma[SIZE][SIZE];

    lerMatriz(matriz1, "1");
    lerMatriz(matriz2, "2");
    somaMatrizes(matriz1, matriz2, matrizSoma);
    exibirMatriz(matrizSoma);

    return 0;
}

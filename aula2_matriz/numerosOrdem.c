//crie um programa que ggere a matriz 3x3:
// 123456789 

#include <stdio.h>

int main() {
    int matriz[3][3];
    int valor = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = valor++;
        }
    }

    printf("Matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// crie 1 matriz 3x3 e verifique se sao simetricas. para verificar, considere que uma matriz simetrica tem os elementos m[lin][col] iguais a m[col][lin]

#include <stdio.h>

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    int simetrica = 1;

    printf("Matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = 0;
                break;
            }
        }
        if (!simetrica) break;
    }

    if (simetrica) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    return 0;
}

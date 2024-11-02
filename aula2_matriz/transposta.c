// consederando que uma matriz transposta é a qeu troca a linha de uma matriz existente por colunas, crie um programa que gere m1 e sua trasposta

// m1           m2
// 123          147      
// 456          258
// 789          369

#include <stdio.h>

int main() {
    int m1[3][3];
    int m2[3][3];
    int valor = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1[i][j] = valor++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m2[j][i] = m1[i][j];
        }
    }

    printf("Matriz M1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz M2 (Transposta):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    float notas[3][3];

    for (int i = 0; i < 3; i++) {
        printf("Digite as notas do aluno %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    printf("\nMatriz de Notas:\n");
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%.1f ", notas[i][j]);
        }
        printf("\n");
    }

    return 0;
}

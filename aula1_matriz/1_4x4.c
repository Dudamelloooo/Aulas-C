#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    float notas[3][3];

    for (int lin = 0; lin < 3; lin++) {
        printf("Digite as notas do aluno %d:\n", lin + 1);
        for (int col = 0; col < 3; col++) {
            printf("Nota %d: ", col + 1);
            scanf("%f", &notas[lin][col]);
        }
    }

    printf("\nMatriz de Notas:\n");
    for (int lin = 0; lin < 3; lin++) {
        printf("Aluno %d: ", lin + 1);
        for (int col = 0; col < 3; col++) {
            printf("%.1f ", notas[lin][col]);
        }
        printf("\n");
    }

    return 0;
}

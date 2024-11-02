#include <stdio.h>

typedef struct {
    float valor;
} Produto;

int main() {
    Produto matriz[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor: [%d][%d] ", i + 1, j + 1);
            scanf("%f", &matriz[i][j].valor);
        }
    }

    printf("Valores:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", matriz[i][j].valor);
        }
        printf("\n");
    }

    return 0;
}

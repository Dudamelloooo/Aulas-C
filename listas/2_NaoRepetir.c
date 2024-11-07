#include <stdio.h>

int main() {
    int numeros[10];
    int i = 0, j;
    int unico;

    while (i < 10) {
        printf("Digite o valor para o elemento %d: ", i + 1);
        scanf("%d", &numeros[i]);
        i++;
    }

    printf("Valores que aparecem apenas uma vez:\n");

    i = 0;
    while (i < 10) {
        unico = 1;
        j = 0;
        while (j < 10) {
            if (i != j && numeros[i] == numeros[j]) {
                unico = 0;
                break;
            }
            j++;
        }
        if (unico) {
            printf("%d ", numeros[i]);
        }
        i++;
    }

    printf("\n");

    return 0;
}

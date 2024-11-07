#include <stdio.h>

int main() {
    int num, maior, menor;

    printf("Digite o 1o numero: ");
    scanf("%d", &num);
    maior = menor = num;

    for (int i = 1; i < 10; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &num);

        maior = (num > maior) ? num : maior;
        menor = (num < menor) ? num : menor;
    }

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
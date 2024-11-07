#include <stdio.h>

int main() {
    int numeros[10];
    int soma = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o valor para o elemento %d: ", i + 1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    printf("A soma é: %d\n", soma);

    return 0;
}

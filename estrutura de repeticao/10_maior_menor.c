#include <stdio.h>

int main() {
    int count = 0;
    int number = 1;

    printf("Os cinco primeiros múltiplos de 3 maiores que 0 são:\n");
    while (count < 5) {
        if (number % 3 == 0) {
            printf("%d\n", number);
            count++;
        }
        number++;
    }

    return 0;
}
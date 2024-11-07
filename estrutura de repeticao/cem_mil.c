#include <stdio.h>

int main() {
    int num = 0;

    while (num <= 100000) {
        printf("%d\n", num);
        num += 100;
    }

    return 0;
}
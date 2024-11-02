#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); 
    int lin, col;
    int matriz[3][4];

    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col < 4; col++) { //quando a col der 4 vai pra lin 1
            matriz[lin][col] = 1;
        }
    }

    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col < 4; col++) {
            printf("%d ", matriz[lin][col]);
        }
        printf("\n");
    }

    return 0;
}

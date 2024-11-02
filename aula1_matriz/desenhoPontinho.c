#include <stdio.h>

int main() {
    int n = 5;
    char matriz[5][5];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == 0 || j == 0 || j == n - 1 || i == n - 1 || i + j == n - 1) {
                matriz[i][j] = '*';
            } else {
                matriz[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

 return  0;

}
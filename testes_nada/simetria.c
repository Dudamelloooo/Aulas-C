#include <stdio.h>
#include <locale.h>

int main() {
    setlocale (LC_ALL, "pt_BR.UTF-8");

    int matriz[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    int simetrica = 1;

    for (int i = 0; i < 3 && simetrica; i++)
        for (int j = 0; j < i; j++)
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = 0;
                break;
            }

    printf("A matriz %s simétrica.\n", simetrica ? "é" : "não é");
    return 0;
}

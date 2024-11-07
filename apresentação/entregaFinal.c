#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_PRODUTOS 50

typedef struct {
    char nome[50];
    float precoPorKg, peso, valorTotal;
} Produto;

int autenticar(const char* esperado, const char* mensagem) {
    char entrada[50];
    printf("%s", mensagem);
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;
    return strcmp(entrada, esperado) == 0;
}

void adicionarProduto(Produto* carrinho, int* numProdutos, float* totalCompra, int tipo) {
    Produto produtoTemp;
    if (*numProdutos >= MAX_PRODUTOS) {
        printf("Carrinho cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    printf("Digite o nome do produto: ");
    fgets(produtoTemp.nome, sizeof(produtoTemp.nome), stdin);
    produtoTemp.nome[strcspn(produtoTemp.nome, "\n")] = 0;

    if (tipo == 1) { // Produto normal
        printf("Digite o valor do produto: ");
        if (scanf("%f", &produtoTemp.valorTotal) != 1 || produtoTemp.valorTotal <= 0) {
            printf("Valor inválido. Tente novamente.\n");
            while (getchar() != '\n');
            return;
        }
        produtoTemp.precoPorKg = 0;
        produtoTemp.peso = 0;
    } else if (tipo == 2) { // Hortifruti
        printf("Digite o preço por quilo: ");
        if (scanf("%f", &produtoTemp.precoPorKg) != 1 || produtoTemp.precoPorKg <= 0) {
            printf("Preço por quilo inválido. Tente novamente.\n");
            while (getchar() != '\n');
            return;
        }

        printf("Digite o peso do produto (em kg): ");
        if (scanf("%f", &produtoTemp.peso) != 1 || produtoTemp.peso <= 0) {
            printf("Peso inválido. Tente novamente.\n");
            while (getchar() != '\n');
            return;
        }
        produtoTemp.valorTotal = produtoTemp.precoPorKg * produtoTemp.peso;
    }

    *totalCompra += produtoTemp.valorTotal;
    carrinho[*numProdutos] = produtoTemp;
    (*numProdutos)++;
    printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", produtoTemp.nome, *totalCompra);
}

void verCarrinho(Produto* carrinho, int numProdutos, float totalCompra) {
    printf("\nCarrinho de compras:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d: %s - ", i + 1, carrinho[i].nome);
        if (carrinho[i].peso > 0)
            printf("Peso: %.2f kg, Preço por kg: R$%.2f, Total: R$%.2f\n", carrinho[i].peso, carrinho[i].precoPorKg, carrinho[i].valorTotal);
        else
            printf("Total: R$%.2f\n", carrinho[i].valorTotal);
    }
    printf("Total da compra até agora: R$%.2f\n", totalCompra);
}

void finalizarCompra(float totalCompra) {
    float valorPago, troco;

    printf("Total da compra: R$%.2f\n", totalCompra);
    printf("Digite o valor pago pelo cliente: ");
    if (scanf("%f", &valorPago) != 1 || valorPago < totalCompra) {
        printf("Valor pago insuficiente ou inválido. Compra não finalizada.\n");
        while (getchar() != '\n');
        return;
    }

    troco = valorPago - totalCompra;
    printf("Troco: R$%.2f\n", troco);
    printf("Compra realizada com sucesso.\n");
}

int main() {
    setlocale(LC_ALL, "");

    const char *coUser = "adm";
    const char *coPassword = "12345";
    int tentativas = 3;
    int escolha;
    float totalCompra = 0;
    Produto carrinho[MAX_PRODUTOS];
    int numProdutos = 0;

    // Autenticação com controle de tentativas
    while (tentativas > 0) {
        if (autenticar(coUser, "Usuário:\n") && autenticar(coPassword, "Senha:\n")) {
            printf("Bem-vindo!\n");
            break;
        }
        tentativas--;
        if (tentativas > 0) {
            printf("Usuário ou senha incorretos! Tentativas restantes: %d\n", tentativas);
        } else {
            printf("Número máximo de tentativas atingido.\n");
            return 0;
        }
    }

    // Loop principal
    while (1) {
        printf("\nEscolha o tipo de produto:\n1. Produto normal\n2. Hortifruti\n3. Ver carrinho\n0. Finalizar\nDigite sua escolha: ");
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }
        getchar(); // Limpa o buffer

        switch (escolha) {
            case 1:
                adicionarProduto(carrinho, &numProdutos, &totalCompra, 1);
                break;
            case 2:
                adicionarProduto(carrinho, &numProdutos, &totalCompra, 2);
                break;
            case 3:
                verCarrinho(carrinho, numProdutos, totalCompra);
                break;
            case 0:
                finalizarCompra(totalCompra);
                return 0;
            default:
                printf("Escolha inválida. Por favor, selecione uma opção válida.\n");
                break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <locale.h> 
#include <string.h> 
#include <stdlib.h> 

#define MAX 50 //para o carrinho

typedef struct { //typedef- criar um novo nome (ou alias) tipo de dado existente. + struct, ele define uma nova estrutura com um nome mais simples e fácil de usar.
    char nome[50];
    float pKg, peso, total;
} Prod;

Prod carrinho[MAX]; //defini que o max pé 50
int nProd = 0;
float totalCompra = 0;

int auth(const char* esperado, const char* msg);  //msg linha 56 e 57 (usuario e senha)
void login(const char *user, const char *pass); //const:valor apontado não pode ser alterado. //char*: Um ponteiro para um caractere (string). //esperado: O nome do parâmetro.
void menu(); //lin 95
void addProd();
void addHorti();
void showCarrinho();
void saveCarrinho();
void finalizar(); // void nao retorna nada, é o 'vazio'

int main() {
    setlocale(LC_ALL, ""); 
    
    const char *user = "adm"; // conts pq n altera, char declara o ponteiro (string), user é o nome da var qeu armazena a string,"adm": String literal atribuída à variável user.
    const char *pass = "12345";
    
    login(user, pass); // user é o primeiro argumento
    menu(); // menu é sem parametro

    return 0;
}

int auth(const char* esperado, const char* msg) { //pobteiro para caractere q chama esperado
    char input[50]; //aqui armazeno a entrada dos usuarios
    printf("%s", msg);
    fgets(input, sizeof(input), stdin); //fgets le e armazena no aray input //sizeof(input) garante so é 50
    input[strcspn(input, "\n")] = 0; // troca o \n por 0/nulo
    return strcmp(input, esperado) == 0; // retorna 1 se as strings forem iguais e 0 caso nao
}

void login(const char *user, const char *pass) {
    int tries = 3; //var tentativas começa em 3

    while (tries > 0) {
        if (auth(user, "Usuário:\n") && auth(pass, "Senha:\n")) { // AQUI A MENSAGEM //auth com user e a string "Usuário:\n". // && é e //auth verifica se o usuário é válido.
            printf("Bem-vindo!\n"); 
            return;
        }
        tries--; // caso erre, as tentativas diminuem e recomeça
        if (tries > 0) { // se as tentarivas + 0 
            printf("Usuário ou senha incorretos! Tentativas restantes: %d\n", tries);
        } else {
            printf("Número máximo de tentativas atingido.\n");
            exit(0); //termina em 0 pq deu certp
        }
    }
}

void menu() {
    int opc;

    while (1) {
        printf("\nEscolha o tipo de produto:\n1. Produto normal\n2. Hortifruti\n3. Ver carrinho\n0. Finalizar\nDigite sua escolha: ");
        
        if (scanf("%d", &opc) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); //limpa o buffer
            continue;
        }

        while (getchar() != '\n');

        switch (opc) {
            case 1:
                addProd();
                break;
            case 2:
                addHorti();
                break;
            case 3:
                showCarrinho();
                break;
            case 0:
                finalizar();
                return;
            default:
                printf("Escolha inválida. Por favor, selecione uma opção válida.\n");
                break;
        }
    }
}

void addProd() {
    if (nProd >= MAX) {
        printf("Carrinho cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    Prod p;
    printf("Digite o nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("Digite o valor do produto: ");
    if (scanf("%f", &p.total) != 1 || p.total <= 0) { /// != 1 significa que a leitura falhou. // || é ou menor ou igual a 0 sao invalidos
        printf("Valor inválido. Tente novamente.\n");
        while (getchar() != '\n');
        return;
    }

    p.pKg = 0;
    p.peso = 0;
    carrinho[nProd++] = p;
    totalCompra += p.total;

    printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", p.nome, totalCompra);
}

void addHorti() {
    if (nProd >= MAX) {
        printf("Carrinho cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    Prod p;
    printf("Digite o nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("Digite o preço por quilo: ");
    if (scanf("%f", &p.pKg) != 1 || p.pKg <= 0) {
        printf("Preço por quilo inválido. Tente novamente.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Digite o peso do produto (em kg): ");
    if (scanf("%f", &p.peso) != 1 || p.peso <= 0) {
        printf("Peso inválido. Tente novamente.\n");
        while (getchar() != '\n');
        return;
    }

    p.total = p.pKg * p.peso;
    carrinho[nProd++] = p;
    totalCompra += p.total;

    printf("Produto '%s' adicionado ao carrinho. Total atual: R$%.2f\n", p.nome, totalCompra);
}

void showCarrinho() {
    if (nProd == 0) {
        printf("Carrinho vazio.\n");
        return;
    }

    printf("\nCarrinho de compras:\n");
    for (int i = 0; i < nProd; i++) { //loop pra lista de itens
        printf("Produto %d: %s - ", i + 1, carrinho[i].nome); //contagem dos produtos comece em 1.
        if (carrinho[i].peso > 0) //contagem dos produtos comece em 1.
            printf("Peso: %.2f kg, Preço por kg: R$%.2f, Total: R$%.2f\n", carrinho[i].peso, carrinho[i].pKg, carrinho[i].total);
        else
            printf("Total: R$%.2f\n", carrinho[i].total);
    }
    printf("Total da compra até agora: R$%.2f\n", totalCompra);
}

void saveCarrinho() {
    FILE *file = fopen("carrinho.txt", "w"); // file file pra manipular arquivov// abre o txt e w pra criar se n tiver
    if (file == NULL) { //  erro se n abrir
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }
    for (int i = 0; i < nProd; i++) { 
        fprintf(file, "%s %.2f %.2f %.2f\n", carrinho[i].nome, carrinho[i].pKg, carrinho[i].peso, carrinho[i].total);
    }
    fclose(file); // fecha o file do ponteiro file
    printf("Carrinho salvo no arquivo com sucesso.\n");
}

void finalizar() {
    float pago, troco;

    printf("Total da compra: R$%.2f\n", totalCompra);
    printf("Digite o valor pago pelo cliente: ");
    if (scanf("%f", &pago) != 1 || pago < totalCompra) { // pra caso digite algo q n é nmr
        printf("Valor pago insuficiente ou inválido. Compra não finalizada.\n");
        while (getchar() != '\n');
        return;
    }

    troco = pago - totalCompra;
    printf("Troco: R$%.2f\n", troco);
    printf("Compra realizada com sucesso.\n");
    saveCarrinho();
}

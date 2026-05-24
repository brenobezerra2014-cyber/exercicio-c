#include <stdio.h>
#include <string.h>

#define TAM 100

struct Conta {
    int numero;
    char nome[50];
    char cpf[20];
    char telefone[20];
    float saldo;
};

// (a)
int buscarConta(struct Conta contas[], int qtd, int numeroConta) {

    int i;

    if(qtd == 0) {
        return -2;
    }

    for(i = 0; i < qtd; i++) {

        if(contas[i].numero == numeroConta) {
            return i;
        }
    }

    return -1;
}

// (b)
void cadastrarConta(struct Conta contas[], int *qtd, int numeroConta) {

    int posicao;

    posicao = buscarConta(contas, *qtd, numeroConta);

    if(posicao != -1) {

        printf("\nConta ja cadastrada!\n");
        return;
    }

    contas[*qtd].numero = numeroConta;

    printf("Nome: ");
    scanf(" %[^\n]", contas[*qtd].nome);

    printf("CPF: ");
    scanf(" %[^\n]", contas[*qtd].cpf);

    printf("Telefone: ");
    scanf(" %[^\n]", contas[*qtd].telefone);

    printf("Saldo inicial: ");
    scanf("%f", &contas[*qtd].saldo);

    (*qtd)++;

    printf("\nConta cadastrada com sucesso!\n");
}

// (c)
void listarContas(struct Conta contas[], int qtd) {

    int i;

    if(qtd == 0) {

        printf("\nNenhuma conta cadastrada!\n");
        return;
    }

    printf("\n=== LISTA DE CONTAS ===\n");

    for(i = 0; i < qtd; i++) {

        printf("\nConta: %d\n", contas[i].numero);
        printf("Nome: %s\n", contas[i].nome);
        printf("CPF: %s\n", contas[i].cpf);
        printf("Telefone: %s\n", contas[i].telefone);
        printf("Saldo: %.2f\n", contas[i].saldo);
    }
}

// (d)
void realizarDeposito(struct Conta contas[], int qtd) {

    int numeroConta, posicao;
    float valor;

    printf("\nNumero da conta: ");
    scanf("%d", &numeroConta);

    posicao = buscarConta(contas, qtd, numeroConta);

    if(posicao < 0) {

        printf("\nConta nao encontrada!\n");
        return;
    }

    printf("Valor do deposito: ");
    scanf("%f", &valor);

    contas[posicao].saldo += valor;

    printf("\nDeposito realizado com sucesso!\n");
}

// (e)
void realizarSaque(struct Conta contas[], int qtd) {

    int numeroConta, posicao;
    float valor;

    printf("\nNumero da conta: ");
    scanf("%d", &numeroConta);

    posicao = buscarConta(contas, qtd, numeroConta);

    if(posicao < 0) {

        printf("\nConta nao encontrada!\n");
        return;
    }

    printf("Valor do saque: ");
    scanf("%f", &valor);

    if(valor > contas[posicao].saldo) {

        printf("\nSaldo insuficiente!\n");
        return;
    }

    contas[posicao].saldo -= valor;

    printf("\nSaque realizado com sucesso!\n");
}

int main() {

    struct Conta contas[TAM];

    int qtd = 0;
    int opcao;
    int numeroConta;

    do {

        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Listar contas\n");
        printf("3 - Deposito\n");
        printf("4 - Saque\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                printf("Numero da conta: ");
                scanf("%d", &numeroConta);

                cadastrarConta(contas, &qtd, numeroConta);

                break;

            case 2:

                listarContas(contas, qtd);

                break;

            case 3:

                realizarDeposito(contas, qtd);

                break;

            case 4:

                realizarSaque(contas, qtd);

                break;

            case 0:

                printf("\nPrograma encerrado!\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

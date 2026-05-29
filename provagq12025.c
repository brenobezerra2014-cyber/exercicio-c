#include <stdio.h>
#include <string.h>

struct Produto {
    int id;
    char descricao[20];
    int qtdEstoque;
    float vlrUnit;
};

struct Venda {
    int id;
    int qtdProdutosVendidos;
    int idsProdutos[5];
    int qtdsVendidas[5];
};


// QUESTÃO 1
void buscaSequencialDesc(struct Produto v[], int tam, char x[]) {

    int i;
    int achou = 0;

    for(i = 0; i < tam; i++) {

        if(strcmp(v[i].descricao, x) == 0) {

            printf("Produto encontrado na posicao %d\n", i);

            achou = 1;
        }
    }

    if(achou == 0) {
        printf("Produto nao encontrado\n");
    }
}


// QUESTÃO 2
void buscaBinariaId(struct Venda v[], int tam, int x) {

    int inicio = 0;
    int fim = tam - 1;
    int meio;
    int achou = 0;

    while(inicio <= fim) {

        meio = (inicio + fim) / 2;

        if(v[meio].id == x) {

            printf("Venda encontrada na posicao %d\n", meio);

            achou = 1;

            break;
        }

        else if(x < v[meio].id) {

            fim = meio - 1;
        }

        else {

            inicio = meio + 1;
        }
    }

    if(achou == 0) {

        printf("Venda nao encontrada\n");
    }
}


// QUESTÃO 3
void alteraProduto(struct Produto v[], int tam) {

    char desc[20];
    int pos = -1;
    int i;
    char op;

    printf("Digite a descricao do produto: ");
    scanf(" %[^\n]", desc);

    for(i = 0; i < tam; i++) {

        if(strcmp(v[i].descricao, desc) == 0) {

            pos = i;
        }
    }

    if(pos == -1) {

        printf("Produto nao encontrado\n");

        return;
    }

    printf("Deseja alterar descricao? (s/n): ");
    scanf(" %c", &op);

    if(op == 's' || op == 'S') {

        printf("Nova descricao: ");
        scanf(" %[^\n]", v[pos].descricao);
    }

    printf("Deseja alterar estoque? (s/n): ");
    scanf(" %c", &op);

    if(op == 's' || op == 'S') {

        printf("Novo estoque: ");
        scanf("%d", &v[pos].qtdEstoque);
    }

    printf("Deseja alterar valor? (s/n): ");
    scanf(" %c", &op);

    if(op == 's' || op == 'S') {

        printf("Novo valor: ");
        scanf("%f", &v[pos].vlrUnit);
    }

    printf("Produto alterado com sucesso\n");
}


// QUESTÃO 4
void venda(struct Produto vp[], int tamProd,
           struct Venda vv[], int tamVendas) {

    int i, j;
    int idVenda;
    int qtdDif;
    char desc[20];
    int posProd;
    int qtd;
    int existe;

    do {

        existe = 0;

        printf("Digite o ID da venda: ");
        scanf("%d", &idVenda);

        for(i = 0; i < tamVendas; i++) {

            if(vv[i].id == idVenda) {

                existe = 1;
            }
        }

        if(existe == 1) {

            printf("ID ja cadastrado\n");
        }

    } while(existe == 1);

    vv[tamVendas].id = idVenda;

    do {

        printf("Quantidade de produtos diferentes (1 a 5): ");
        scanf("%d", &qtdDif);

    } while(qtdDif < 1 || qtdDif > 5);

    vv[tamVendas].qtdProdutosVendidos = qtdDif;

    for(i = 0; i < qtdDif; i++) {

        posProd = -1;

        do {

            printf("Descricao do produto: ");
            scanf(" %[^\n]", desc);

            for(j = 0; j < tamProd; j++) {

                if(strcmp(vp[j].descricao, desc) == 0 &&
                   vp[j].qtdEstoque > 0) {

                    posProd = j;
                }
            }

            if(posProd == -1) {

                printf("Produto invalido ou sem estoque\n");
            }

        } while(posProd == -1);

        vv[tamVendas].idsProdutos[i] = vp[posProd].id;

        do {

            printf("Quantidade vendida: ");
            scanf("%d", &qtd);

        } while(qtd < 1 || qtd > vp[posProd].qtdEstoque);

        vv[tamVendas].qtdsVendidas[i] = qtd;

        vp[posProd].qtdEstoque =
            vp[posProd].qtdEstoque - qtd;
    }

    printf("Venda realizada com sucesso\n");
}


// QUESTÃO 5
void relatorio(struct Produto vp[], int tamProd,
               struct Venda vv[], int tamVendas) {

    int i, j, k;
    int totalItens;
    int posProd;
    float totalProduto;
    float totalGeral;

    for(i = 0; i < tamVendas; i++) {

        totalItens = 0;

        for(j = 0; j < vv[i].qtdProdutosVendidos; j++) {

            totalItens =
                totalItens + vv[i].qtdsVendidas[j];
        }

        if(totalItens > 2) {

            totalGeral = 0;

            printf("\n+-------------------------------------------+\n");
            printf("|               VENDA %03d                 |\n",
                   vv[i].id);
            printf("+-------------------------------------------+\n");

            printf("+---+--------------------+--------+---------+\n");
            printf("|QTD| DESCRICAO          |VLR UNIT|VLR TOTAL|\n");
            printf("+---+--------------------+--------+---------+\n");

            for(j = 0; j < vv[i].qtdProdutosVendidos; j++) {

                posProd = -1;

                for(k = 0; k < tamProd; k++) {

                    if(vp[k].id == vv[i].idsProdutos[j]) {

                        posProd = k;
                    }
                }

                if(posProd != -1) {

                    totalProduto =
                        vv[i].qtdsVendidas[j] *
                        vp[posProd].vlrUnit;

                    totalGeral =
                        totalGeral + totalProduto;

                    printf("|%3d|%-20s|%8.2f|%9.2f|\n",
                           vv[i].qtdsVendidas[j],
                           vp[posProd].descricao,
                           vp[posProd].vlrUnit,
                           totalProduto);
                }
            }

            printf("+---+--------------------+--------+---------+\n");

            printf("|   |Total Geral         |        |%9.2f|\n",
                   totalGeral);

            printf("+---+--------------------+--------+---------+\n");
        }
    }
}

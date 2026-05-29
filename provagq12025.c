#include <stdio.h>
#include <string.h>

#define TAM_PROD 100
#define TAM_VENDAS 100

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
int buscaSequencialDesc(struct Produto v[], int tam, char x[]) {
    int i;

    for(i = 0; i < tam; i++) {
        if(strcmp(v[i].descricao, x) == 0) {
            return i;
        }
    }

    return -1;
}


// QUESTÃO 2
int buscaBinariaId(struct Venda v[], int tam, int x) {
    int ini = 0;
    int fim = tam - 1;
    int meio;

    while(ini <= fim) {
        meio = (ini + fim) / 2;

        if(v[meio].id == x) {
            return meio;
        }
        else if(x < v[meio].id) {
            fim = meio - 1;
        }
        else {
            ini = meio + 1;
        }
    }

    return -1;
}


// QUESTÃO 3
int alteraProduto(struct Produto v[], int tam) {
    char desc[20];
    int pos;
    char op;

    printf("Digite a descricao do produto: ");
    scanf(" %[^\n]", desc);

    pos = buscaSequencialDesc(v, tam, desc);

    if(pos == -1) {
        return 0;
    }

    printf("Deseja alterar a descricao? (s/n): ");
    scanf(" %c", &op);

    if(op == 's' || op == 'S') {
        printf("Nova descricao: ");
        scanf(" %[^\n]", v[pos].descricao);
    }

    printf("Deseja alterar a quantidade em estoque? (s/n): ");
    scanf(" %c", &op);

    if(op == 's' || op == 'S') {
        printf("Nova quantidade: ");
        scanf("%d", &v[pos].qtdEstoque);
    }

    printf("Deseja alterar o valor unitario? (s/n): ");
    scanf(" %c", &op);

    if(op == 's' || op == 'S') {
        printf("Novo valor: ");
        scanf("%f", &v[pos].vlrUnit);
    }

    return 1;
}


// QUESTÃO 4
void venda(struct Produto vp[], int tamProd, struct Venda vv[], int tamVendas) {
    int i, j;
    int idVenda;
    int qtdDif;
    char desc[20];
    int posProd;
    int qtd;

    printf("Digite o ID da venda: ");
    scanf("%d", &idVenda);

    while(buscaBinariaId(vv, tamVendas, idVenda) != -1) {
        printf("ID ja existente. Digite outro: ");
        scanf("%d", &idVenda);
    }

    vv[tamVendas].id = idVenda;

    printf("Quantidade de produtos diferentes (1 a 5): ");
    scanf("%d", &qtdDif);

    while(qtdDif < 1 || qtdDif > 5) {
        printf("Valor invalido. Digite novamente: ");
        scanf("%d", &qtdDif);
    }

    vv[tamVendas].qtdProdutosVendidos = qtdDif;

    for(i = 0; i < qtdDif; i++) {

        do {
            printf("Descricao do produto: ");
            scanf(" %[^\n]", desc);

            posProd = buscaSequencialDesc(vp, tamProd, desc);

            if(posProd == -1 || vp[posProd].qtdEstoque == 0) {
                printf("Produto invalido ou sem estoque.\n");
            }

        } while(posProd == -1 || vp[posProd].qtdEstoque == 0);

        vv[tamVendas].idsProdutos[i] = vp[posProd].id;

        printf("Quantidade vendida: ");
        scanf("%d", &qtd);

        while(qtd < 1 || qtd > vp[posProd].qtdEstoque) {
            printf("Quantidade invalida. Digite novamente: ");
            scanf("%d", &qtd);
        }

        vv[tamVendas].qtdsVendidas[i] = qtd;

        vp[posProd].qtdEstoque -= qtd;
    }
}


// QUESTÃO 5
void relatorio(struct Produto vp[], int tamProd, struct Venda vv[], int tamVendas) {
    int i, j, k;
    int totalItens;
    float totalGeral;
    int posProd;
    float totalProduto;

    for(i = 0; i < tamVendas; i++) {

        totalItens = 0;

        for(j = 0; j < vv[i].qtdProdutosVendidos; j++) {
            totalItens += vv[i].qtdsVendidas[j];
        }

        if(totalItens > 2) {

            totalGeral = 0;

            printf("\n+-------------------------------------------+\n");
            printf("|              VENDA N.%03d               |\n", vv[i].id);
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
                        vv[i].qtdsVendidas[j] * vp[posProd].vlrUnit;

                    totalGeral += totalProduto;

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

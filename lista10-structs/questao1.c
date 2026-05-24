#include <stdio.h>

#define TAM 26

struct Estado {
    char nome[50];
    int veiculos;
    int acidentes;
};

// letra a
void cadastrarEstados(struct Estado estados[]) {
    int i;

    for(i = 0; i < TAM; i++) {
        printf("\nEstado %d\n", i + 1);

        printf("Nome do estado: ");
        scanf(" %[^\n]", estados[i].nome);

        printf("Numero de veiculos: ");
        scanf("%d", &estados[i].veiculos);

        printf("Numero de acidentes: ");
        scanf("%d", &estados[i].acidentes);
    }
}

// letra b
void maiorMenorAcidente(struct Estado estados[], int *maior, int *menor) {
    int i;

    *maior = 0;
    *menor = 0;

    for(i = 1; i < TAM; i++) {

        if(estados[i].acidentes > estados[*maior].acidentes) {
            *maior = i;
        }

        if(estados[i].acidentes < estados[*menor].acidentes) {
            *menor = i;
        }
    }
}

// letra c
float percentualAcidentes(struct Estado estados[], int posicao) {

    return ((float) estados[posicao].acidentes /
            estados[posicao].veiculos) * 100;
}

// letra d
float mediaAcidentes(struct Estado estados[]) {

    int i, soma = 0;

    for(i = 0; i < TAM; i++) {
        soma += estados[i].acidentes;
    }

    return (float) soma / TAM;
}

// leta e
void acimaMedia(struct Estado estados[], float media) {

    int i;

    printf("\nEstados acima da media:\n");

    for(i = 0; i < TAM; i++) {

        if(estados[i].acidentes > media) {

            printf("%s\n", estados[i].nome);
        }
    }
}

int main() {

    struct Estado estados[TAM];

    int maior, menor, i;

    float media;

    // (a)
    cadastrarEstados(estados);

    // (b)
    maiorMenorAcidente(estados, &maior, &menor);

    printf("\nMaior numero de acidentes:\n");
    printf("%s - %d acidentes\n",
           estados[maior].nome,
           estados[maior].acidentes);

    printf("\nMenor numero de acidentes:\n");
    printf("%s - %d acidentes\n",
           estados[menor].nome,
           estados[menor].acidentes);

    // (c)
    printf("\nPercentual de acidentes:\n");

    for(i = 0; i < TAM; i++) {

        printf("%s: %.2f%%\n",
               estados[i].nome,
               percentualAcidentes(estados, i));
    }

    // (d)
    media = mediaAcidentes(estados);

    printf("\nMedia de acidentes no pais: %.2f\n", media);

    // (e)
    acimaMedia(estados, media);

    return 0;
}

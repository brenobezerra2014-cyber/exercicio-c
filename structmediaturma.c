#include <stdio.h>

#define TAM 30

struct Aluno {
    float nota1;
    float nota2;
    float media;
};

void preencherAluno(struct Aluno *a);
void calcularMediaAluno(struct Aluno *a);
float calcularMediaTurma(struct Aluno alunos[], int n);
void imprimirAcimaMedia(struct Aluno alunos[], int n, float media);
// main
int main() {
    struct Aluno alunos[TAM];
    float mediaTurma;

    for (int i = 0; i < TAM; i++) {
        preencherAluno(&alunos[i]);
        calcularMediaAluno(&alunos[i]);
    }

    mediaTurma = calcularMediaTurma(alunos, TAM);
    //media da turma geral
    printf("%.2f\n", mediaTurma);

    imprimirAcimaMedia(alunos, TAM, mediaTurma);

    return 0;
}
// Função para preencher as notas do aluno
void preencherAluno(struct Aluno *a) {
    scanf("%f", &a->nota1);
    scanf("%f", &a->nota2);
}
// Função para calcular a média de um aluno
void calcularMediaAluno(struct Aluno *a) {
    a->media = (2 * a->nota1 + 3 * a->nota2) / 5;
}
//  calcular  a media da turma
float calcularMediaTurma(struct Aluno alunos[], int n) {
    float soma = 0;

    for (int i = 0; i < n; i++) {
        soma += alunos[i].media;
    }

    return soma / n;
}
//  imprimir alunos acima da média da turma
void imprimirAcimaMedia(struct Aluno alunos[], int n, float media) {
    for (int i = 0; i < n; i++) {
        if (alunos[i].media > media) {
            printf("%.2f %.2f %.2f\n",
                   alunos[i].nota1,
                   alunos[i].nota2,
                   alunos[i].media);
        }
    }
}

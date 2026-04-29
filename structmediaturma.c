#include <stdio.h>

#define TAM 30

struct Aluno {
    double nota1;
    double nota2;
    double media;
};

void preencherAluno(struct Aluno *a);
void calcularMediaAluno(struct Aluno *a);
float calcularMediaTurma(struct Aluno alunos[], int n);
void imprimirAcimaMedia(struct Aluno alunos[], int n, double media);
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
    printf("%.2lf\n", mediaTurma);

    imprimirAcimaMedia(alunos, TAM, mediaTurma);

    return 0;
}
// Função para preencher as notas do aluno
void preencherAluno(struct Aluno *a) {
    scanf("%lf", &a->nota1);
    scanf("%lf", &a->nota2);
}
// Função para calcular a média de um aluno
void calcularMediaAluno(struct Aluno *a) {
    a->media = (2 * a->nota1 + 3 * a->nota2) / 5;
}
//  calcular  a media da turma
double calcularMediaTurma(struct Aluno alunos[], int n) {
    double soma = 0;

    for (int i = 0; i < n; i++) {
        soma += alunos[i].media;
    }

    return soma / n;
}
//  imprimir alunos acima da média da turma
void imprimirAcimaMedia(struct Aluno alunos[], int n, double media) {
    for (int i = 0; i < n; i++) {
        if (alunos[i].media > media) {
            printf("%.2lf %.2lf %.2lf\n",
                   alunos[i].nota1,
                   alunos[i].nota2,
                   alunos[i].media);
        }
    }
}

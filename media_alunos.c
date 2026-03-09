#include <stdio.h>

int main(){

    double nota1[30], nota2[30], media[30];
    double media_turma = 0;
    int i;

    for(i = 0; i < 30; i++){
        printf("Aluno %d\n", i+1);

        printf("Nota 1: ");
        scanf("%lf", &nota1[i]);

        printf("Nota 2: ");
        scanf("%lf", &nota2[i]);

        media[i] = (nota1[i]*2 + nota2[i]*3)/5;

        media_turma += media[i];
    }

    media_turma = mediaTurma/30;

    printf("\nMedia da turma: %.2lf\n", mediaTurma);


    for(i = 0; i < 30; i++){
        if(media[i] > mediaTurma){
            printf("Aluno %d  Nota1: %.2lf  Nota2: %.2lf  Media: %.2lf\n",  i+1, nota1[i], nota2[i], media[i]);          
        }
    }

    return 0;
}

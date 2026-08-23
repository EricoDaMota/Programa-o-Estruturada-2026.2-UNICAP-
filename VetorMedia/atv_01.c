#include <stdio.h>

#define QTD_ALUNOS 5

void digitaNota(int n1[], int n2[], int n);
void calculaMediaPorAluno(int n1[], int n2[], double med[], int n);
double calculaMediaTurma(double med[], int n);
void imprimeMediaTurma(double medPA[], int n);
void imprimeNotaAcimaMedia(int n1[], int n2[], double med[], int n);

int main(){
    int nota1[QTD_ALUNOS];
    int nota2[QTD_ALUNOS];
    double media[QTD_ALUNOS];
    digitaNota(nota1, nota2, QTD_ALUNOS);
    calculaMediaPorAluno(nota1, nota2, media, QTD_ALUNOS);
    calculaMediaTurma(media, QTD_ALUNOS);
    imprimeMediaTurma(media, QTD_ALUNOS);
    imprimeNotaAcimaMedia(nota1, nota2, media, QTD_ALUNOS);
    
    return 0;
}
void digitaNota(int n1[], int n2[], int n){
    for (int i = 0 ; i < n ; i += 1) {
        printf("Digite a nota1 do aluno(%d/30): ", i + 1);
        scanf("%d", &n1[i]);
        printf("Digite a nota2 do aluno(%d/30): ", i + 1);
        scanf("%d", &n2[i]);
    }
}
void calculaMediaPorAluno(int n1[], int n2[], double medPA[], int n) {
    for (int i = 0 ; i < n ; i += 1) {
        medPA[i] = ((double) n1[i] * 2 + (double) n2[i] * 3) / 5.0;
    }
}

double calculaMediaTurma(double medPA[], int n) {
    double acumulador = 0;
    for (int i = 0 ; i < n ; i += 1) {
        acumulador += medPA[i];
    }
    double mediaTurma = acumulador / n;
    return mediaTurma;
}

void imprimeMediaTurma(double medPA[], int n) {
    printf("A média da turma é: %f\n", calculaMediaTurma(medPA, n));
}

void imprimeNotaAcimaMedia(int n1[], int n2[], double med[], int n){
    double medT = calculaMediaTurma(med, n);
    for (int i = 0 ; i < n ; i += 1) {
        if (medT < med[i]) {
            printf("\nAluno(%d/30):\nnota1 = %d\nnota2 = %d\nMedia = %f\n", i + 1, n1[i], n2[i], med[i]);
        }
    }
}
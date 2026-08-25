#include <stdio.h>

#define QTD_ALUNOS 30

void digitaNota(double n1[], double n2[], int n);
void calculaMediaPorAluno(double n1[], double n2[], double med[], int n);
double calculaMediaTurma(double medPA[], int n);
void imprimeMediaTurma(double medPA[], int n);
void imprimeNotaAcimaMedia(double n1[], double n2[], double med[], int n);

int main(){
    double nota1[QTD_ALUNOS];
    double nota2[QTD_ALUNOS];
    double media[QTD_ALUNOS];
    digitaNota(nota1, nota2, QTD_ALUNOS);
    calculaMediaPorAluno(nota1, nota2, media, QTD_ALUNOS);
    imprimeMediaTurma(media, QTD_ALUNOS);
    imprimeNotaAcimaMedia(nota1, nota2, media, QTD_ALUNOS);
    
    return 0;
}
void digitaNota(double n1[], double n2[], int n){
    for (int i = 0 ; i < n ; i += 1) {
        printf("\nDigite a nota1 do aluno(%d/%d): ", i + 1, n);
        scanf("%lf", &n1[i]);
        while (n1[i] > 10 || n1[i] < 0) {
            printf("\n(0 <= Nota <= 10)!");
            printf("\nDigite a nota1 do aluno(%d/%d): ", i + 1, n);
            scanf("%lf", &n1[i]);
        }
        printf("\nDigite a nota2 do aluno(%d/%d): ", i + 1, n);
        scanf("%lf", &n2[i]);
        while (n2[i] > 10 || n2[i] < 0) {
            printf("(0 <= Nota <= 10)!");
            printf("\nDigite a nota2 do aluno(%d/%d): ", i + 1, n);
            scanf("%lf", &n2[i]);
        }

    }
}
void calculaMediaPorAluno(double n1[], double n2[], double medPA[], int n) {
    for (int i = 0 ; i < n ; i += 1) {
        medPA[i] = (n1[i] * 2 + n2[i] * 3) / 5.0;
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
    printf("A média da turma é: %.1f\n", calculaMediaTurma(medPA, n));
}

void imprimeNotaAcimaMedia(double n1[], double n2[], double med[], int n){
    double medT = calculaMediaTurma(med, n);
    for (int i = 0 ; i < n ; i += 1) {
        if (medT < med[i]) {
            printf("\nAluno(%d/%d):\nnota1 = %.1f\nnota2 = %.1f\nMedia = %.1f\n", i + 1, n,  n1[i],  n2[i], med[i]);
        }
    }
}
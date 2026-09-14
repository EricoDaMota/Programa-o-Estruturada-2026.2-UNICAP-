#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 3

void preencherMatriz(int m[][QTD_COLUNAS], int lins, int coluns);
void imprimirMatriz(int m[][QTD_COLUNAS], int lins, int coluns);
void imprimirMaiorValorMatriz(int m[][QTD_COLUNAS], int lins, int coluns);

int main() {
    int m[QTD_LINHAS][QTD_COLUNAS];
    preencherMatriz(m, QTD_LINHAS, QTD_COLUNAS);
    imprimirMatriz(m, QTD_LINHAS, QTD_COLUNAS);
    imprimirMaiorValorMatriz(m, QTD_LINHAS, QTD_COLUNAS);
    return 0;
}

void preencherMatriz(int m[][QTD_COLUNAS], int lins, int coluns) {
    for (int i = 0 ; i < QTD_LINHAS ; i += 1) {
        for(int j = 0 ; j < QTD_COLUNAS ; j += 1) {
            printf("Digite o valor de m[%d][%d]:\n", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}
void imprimirMatriz(int m[][QTD_COLUNAS], int lins, int coluns){
    for (int i = 0 ; i < QTD_LINHAS ; i += 1) {
        for (int j = 0 ; j < QTD_COLUNAS ; j += 1) {
            printf("%2d", m[i][j]);
        }
        printf("\n");
    }
}

void imprimirMaiorValorMatriz(int m[][QTD_COLUNAS], int lins, int coluns){
    int iMaior = 0 , jMaior = 0;
    for (int i = 0 ; i < lins ; i += 1) {
        for(int j = 0 ; j < coluns ; j += 1) {
            if (m[i][j] > m [iMaior][jMaior]){
                iMaior = i;
                jMaior = j;
            }
        }

    }
}
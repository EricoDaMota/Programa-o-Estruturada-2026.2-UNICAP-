#include <stdio.h>
#define qtd_colunas 4
//q.a
int removerRepetidos(int v[], int tam) {
    if (tam <= 0) return 0;
    int j = 0;
    for (int i = 1; i < tam; i++) {
        if (v[j] != v[i]) {
            j++;
            v[j] = v[i];
        }
    }
    return j + 1;
}

//q.b
void ordenarBubbleSort(int v[], int tam) {
    int trocou = 1, aux;
    while (trocou != 0) {
        trocou = 0;
        for (int i = 0; i < tam - 1; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i + 1];
                v[i + 1] = v[i];
                v[i] = aux;
                trocou = 1;
            }
        }
    }
}
//q.d
void maiorPorLinha(int m[][qtd_colunas], int lin, int col, int v[]) {
    int maior;
    for (int i = 0; i < lin; i++) {
        maior = m[i][0];
        for (int j = 0; j < col - 1; j++) {
            if (m[i][j + 1] > maior) {
                maior = m[i][j + 1];
            }
        }
        v[i] = maior;
    }
}
int main() {
    int v1[] = {7, 2, 5, 2, 8, 1};
    ordenarBubbleSort(v1, 6);

    printf("Ordenado: ");
    for (int i = 0; i < 6; i++) printf("%d ", v1[i]);
    printf("\n");

    int tamLimpo = removerRepetidos(v1, 6);

    printf("Sem repetidos: ");
    for (int i = 0; i < tamLimpo; i++) printf("%d ", v1[i]);
    printf("\n");

    int mat[2][qtd_colunas] = {
        {3, 9, 2, 5},
        {12, 4, 7, 1}
    };
    int maiores[2];

    maiorPorLinha(mat, 2, qtd_colunas, maiores);

    printf("Maiores das linhas: %d %d\n", maiores[0], maiores[1]);

    return 0;
}
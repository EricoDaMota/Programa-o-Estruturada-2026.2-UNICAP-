#include <stdio.h>
#include <string.h>
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

//q.c
int ehPrimo (int v[], int tam, int num) {
    for (int i = 0 ; i < tam ; i += 1) {
        if ( num % v[i] == 0) {
            return 0;
        }
    }
    return 1;

}
void preencherPrimo (int v[], int tam) {
    int num = 2, qtdPrimos = 0;
    while (qtdPrimos < tam) {
        if (ehPrimo(v, qtdPrimos, numt)) {
            v[qtdPrimos] = num;
            qtdPrimos += 1;
        }
        num += 1;
    }
}

//q.d
void maiorPorLinha (int m[][qtd_colunas], int lin, int col, int v[]) {
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

//q.e
void inverterPalavra (char str[], int inicio, int fim) {
    for (int i = 0 ; i < (fim - inicio + 1) / 2 ; i += 1) {
        aux = v[inicio + i];
        str[inicio + 1] = v[fim - i];
        str[fim - i] = aux;
    }
}
void inverterPalavras (char str[]) {
    int tam = strlen(str);
    //intervalo = ultimo numero - primeiro + i
    int inicio = 0, fim;
    for (int i = 0; i  < tam ; i+=1) {
        if (str[i] == ' ') {
            fim = i - 1;
            inverterPalavra(str, inicio, fim);
            inicio = i + 1;
        }
    } 
    inverterPalavra(str, inicio, tam - 1);
}
//metodo 2
void inverterPalavra2 (char str[], int inicio, int fim) {
    char aux;
    while (inicio < fim) {
        aux = str[inicio];
        str[inicio] = str[fim];
        str[fim] = aux;
        inicio += 1;
        fim -= 1;
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
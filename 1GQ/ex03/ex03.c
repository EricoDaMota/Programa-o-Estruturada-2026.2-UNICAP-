#include <stdio.h>

#define TAM 15

int main() {
    int vetor1[TAM], vetor2[TAM], vetor3[TAM];
    PreencherVetor1(vetor1, TAM);
    imprimirVetor1(vetor1, TAM);
}

void PreencherPar(int v1[], int n) {
    int par = 102;
    for (int i = 0 ; i < n ; i += 1) {
        v1[i] = 102 + 2 * i;
    }
}

void imprimirPar(int v1[], int n) {
    printf("{ ");
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d", v1[i]); 
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(" }");
}


int ePrimo(int v2[], int n, int x) {
    for (int i = 0; i < n ; i += 1) {
        if (x % v2[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void preencherPrimo (int v2[], int n) {
    int i = 0, num = 2;
    while (i < n) {
        if (ePrimo(v2, n, num)) {
            v2[i] = num;
            i += 1;
        }
        num += 1;
    }
}

void somatorio (int s[], int v1[], int v2[], int n) {
    int ib = n -1;
    for (int i = 0 ; i < n ; i += 1) {
        //s[]
    }
}
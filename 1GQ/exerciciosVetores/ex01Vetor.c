#include <stdio.h>
#define QTD_MAX 5

void digitaVetor(int v[], int n);
void imprimeVetor(int v[], int n);
void somarVetor(int v[], int n);

int main() {

    int numeros[QTD_MAX];
    digitaVetor(numeros, QTD_MAX);
    imprimeVetor(numeros, QTD_MAX);
    somarVetor(numeros, QTD_MAX);
    return 0;
}

void digitaVetor(int v[], int n) {
    for (int i = 0 ; i < n ; i += 1){
        printf("Digite um valor inteiro(%d/5): ", i);
        scanf("%d", &v[i]);
    }
}
void imprimeVetor(int v[], int n) {
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d\n", v[i]);
    }
}

void somarVetor(int v[], int n) {
    int soma = 0;
    for (int i = 0 ; i < n ; i += 1) {
        soma += v[i];
    }
    printf("A soma de todo os termos do vetor dá: %d\n", soma);
}
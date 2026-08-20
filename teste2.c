#include <stdio.h>
#define QTD 10

void digitaVetor(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("Digite um número:\n");
        scanf("%d", &v[i]);
    }
}

void impressoraVetor(int v[], int n) {
    printf("{");
    if (n > 0) {
        printf("%d", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %d", v[i]);
        }
        printf("}\n");
    }
}

void maiorValorVetor(int v[], int n) {
    int maior = 0; //repreenta o índice e não o valor
    for (int i = 1 ; i < n ; i += 1);
}

void digitaVetor(int v[], int n);
void impressoraVetor(int v[], int n); 

int main() {
    int numeros[QTD];
    digitaVetor(numeros, QTD);
    impressoraVetor(numeros, QTD);
    return 0;
}
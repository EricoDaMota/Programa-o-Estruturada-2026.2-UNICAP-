#include <stdio.h>
#include <stdbool.h>


#define QTD_LIMITE 10


//prototipos
void digitaVetor(int v[], int n);
void imprimeVetor(int v[], int n);
void imprimeMaior (int v[], int n);

//main
int main() {
int numeros[QTD_LIMITE];
digitaVetor(numeros, QTD_LIMITE);
imprimeVetor(numeros, QTD_LIMITE);
imprimeMaior(numeros, QTD_LIMITE);
}

//funções
void digitaVetor(int v[], int n) {
    for (int i = 0 ; i < n ; i += 1){
        printf("Digite um valor(%d/ 10): ", i);
        scanf("%d", &v[i]);
    }
}
void imprimeVetor(int v[], int n) {
    printf("{");
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
void imprimeMaior (int v[], int n) {
    if (n <= 0) return;
    int max = v[0];
    for (int i = 0 ; i < n ; i += 1) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    printf("\nO maior número do vetor é %d\n", max);
}


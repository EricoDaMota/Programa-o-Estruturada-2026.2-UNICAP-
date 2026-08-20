#include <stdio.h>
#include <sdtbool.h>


#define QTD_LIMITE 10


//prototipos
void digitaVetor(int v[], int n);
void imprimeVetor(int v[], int n);

//main
int main() {
int numeros[QTD_LIMITE];
digitaVetor(numeros, QTD_LIMITE);
imprimeVetor(numeros, QTD_LIMITE);
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

void maior (int v[], int n) {
    for (int i = 0 ; i < n ; i += 1) {
        int comparacao;
        int max;

        int comparacao = v[i] > v[i + 1];
        if (comparacao == true) {
            max = v[i];
        } else {

            max = v[i + 1]
        }
    printf("O maior número do vetor é %d", max);
    }
}


#include <stdio.h>

#define TAM 5

void preencherVetor(int v[], int n);
void imprimirVetor(int v[], int n);
void ordenarBubbleSort(int v[], int n);
void imprimirMaiorImpar(int v[], int n);
void criarParesImpares(int v[], int n);

int main() {
    int numeros[TAM];
    preencherVetor(numeros, TAM);
    imprimirVetor(numeros, TAM);
    ordenarBubbleSort(numeros, TAM);
    imprimirVetor(numeros, TAM);
    //imprimirMaiorImpar(numeros, TAM);
    return 0;
}

void preencherVetor(int v[], int n) {
    for (int i = 0 ; i < n ; i += 1) {
        printf("Digite um valor(%d/%d): ", i + 1, n);
        scanf("%d", &v[i]);
    }
}

void imprimirVetor(int v[], int n) {
    printf("{");
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void ordenarBubbleSort(int v[], int n) {
    int aux, limite, trocou, i;
    limite = n - 1;
    trocou = 1;
    while (trocou && limite > 0) {
        trocou = 0;
        i = 0;
        while(i < limite) {
            if (v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                trocou = 1;
            }
            i++;
        }
        limite--;
    }
}
int ehImpar (int x){
    if (x % 2 != 0) {
        return 1;
    }
    return 0;
}

void imprimirMaiorImpar(int v[], int n) {
    int i = 0;
    int existeImpar = 0;
    while (i < n || existeImpar == 1) {
        ehImpar(v[i]);
        if (ehImpar == 1) {
            existeImpar = 1;
            break;
        }
        else if (i == n && existeImpar == 0) {
            printf("Não existe número ímpar!!!");
        }
        i++;
    }
    
}
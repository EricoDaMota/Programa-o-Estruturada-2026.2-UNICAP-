#include <stdio.h>

#define TAM 5

void imprimirVetor(double v[], int n);
void preencherOrdenadoDigitacao(double v[], int n);
void inserirOrdenado(double v[], int n, double x);

int main() {
    double numeros[TAM];
    preencherOrdenadoDigitacao(numeros, TAM);
    imprimirVetor(numeros, TAM);
    return 0;
}


void imprimirVetor(double v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %6.2f", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %6.2f", v[i]);
        }
    }
    printf(" }\n");
}

void preencherOrdenadoDigitacao(double v[], int n) {
    double num;
    for (int i = 0; i < n; i += 1) {
        printf("Digite um número real: ");
        scanf("%lf", &num);
        inserirOrdenado(v, i, num);
    }
}

void inserirOrdenado(double v[], int n, double x) {
    int i = n-1;
    while (i >= 0 && v[i] > x) {
        v[i+1] = v[i];
        i -= 1;
    }
    v[i + 1] = x;
}

int buscarSequenciaMelhorada (double v[], int n, double x) {
    int i;
    for (int i = 0 ; i < n ; i += 1) {
        if (v[i] >= x) {
            break;
        }
    }
    if (i < n && v[i] == x) {
        return 1;
    }
    return -1;
}

int buscaSequencialSentinela (double v[], int n, double x) {
    int i = 0;
    v[n] = x; // vetor precisa ter capcidade pelo menos 1 a mais que o tamanho
    while (v[i] != x) {
        i += 1;
    }
    if (i < n) {
        return 1;
    }
    return -1;
}

int buscaBinaria ( double v[], int n, double chave) {
    int inicio = 0, meio, fim = n - 1;
    do {
        meio = (inicio + fim) / 2;
        if (v[meio] > chave) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    } while (v[meio] != chave && inicio <= fim);
    if (v[meio] == chave) {
        return meio; //returna posiçãodouble
        
}
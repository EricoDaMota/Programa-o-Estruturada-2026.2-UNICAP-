#include <stdio.h>

#define TAM_VETOR 20

void prencherVetor(int vA[], int vB[], int n);
void imprimirDoisVetores (int vA[], int vB[], int n);
int buscarValor (int vA[], int vB[], int p, int n);
int elementoMAX (int vA[], int vB[], int n);

int main() {
    int vetor_A [TAM_VETOR] , vetor_B [TAM_VETOR];
    int opcao;
    prencherVetor(vetor_A, vetor_B, TAM_VETOR);
    do {
        printf("MENU\n");
        printf("1-Imprimir dois vetores;\n");
        printf("2-Buscar um valor em dois vetores;\n");
        printf("3-Encontrar o maior elemento nos dois vetores;\n");
        printf("4-Remover um elemento no vetor A;\n"); 
        printf("5-Remover um elemento no vetor B;\n");
        printf("6-Inserir um valor no início do vetor A;\n");
        printf("7-Inserir um valor no início do vetor B;\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                imprimirDoisVetores(vetor_A, vetor_B, TAM_VETOR);
            
        }
    } while (opcao != 0);
    return 0;
}
void prencherVetor(int vA[], int vB[], int n) {
    //PRENCHER A
    for (int i = 0 ; i < n ; i += 1) {
        printf("Digite um valor para o vetor A(%d/%d): ", i + 1, n);
        scanf("%d", &vA[i]);
    }
    //PRENCHER B
    for (int i = 0 ; i < n ; i += 1) {
        printf("Digite um valor para o vetor B(%d/%d): ", i + 1, n);
        scanf("%d", &vB[i]);
    }
}

void imprimirDoisVetores (int vA[], int vB[], int n) {
    printf("A {");
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d", vA[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    
    printf("B {");
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d", vB[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int buscarValor (int vA[], int vB[], int p, int n) {
    for (int i = 0 ; i < n ; i += 1) {
        if (vA[i] == p || vB[i] == p) {
            return i;
        }
    }
    return -1;
}

int elementoMAX (int vA[], int vB[], int n) {
    int maiorA = vA[0];
    int maiorB = vB[0];
    for (int i = 0 ; i < n ; i += 1) {
        if (vA[i] > maiorA) {
            maiorA = vA[i];
        }
        if (vB[i] > maiorB) {
            maiorB = vB[i];
        }
    }
    if (maiorA > maiorB){
        return maiorA;
    }
    else {
        return maiorB;
    }
}

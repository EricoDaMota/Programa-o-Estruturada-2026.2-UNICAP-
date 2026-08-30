#include <stdio.h>

#define TAM_VETOR 20

int main() {
    int vetorer_A [TAM_VETOR] , vetorer_B [TAM_VETOR];
    int opcao;
    do {
        printf("MENU\n");
        printf("1-Imprimir dois vetores;\n");
        printf("2-Buscar um valor em dois vetores;\n");
        printf("3-Encontrar o maior elemento nos dois vetores;\n");
        printf("4-Remover um elemento no vetor A;\n"); 
        printf("5-Remover um elemento no vetor B;\n");
        printf("6-Inserir um valor no início do vetor A;\n");
        printf("7-Inserir um valor no início do vetor B;\n");
        scanf("d%", &opcao);
        switch (opcao) {
            case 1;
                printf
            
        }
    }
    return 0;
}
void prencherVetor(int vA[], int vB[], int n) {
    //PRENCHER A
    for (int i = 0 ; i < n ; i += 1) {
        printf("Digite um valor para o vetor A(d%/n): ");
        scanf("%d", &vA[i]);
    }
    //PRENCHER B
    for (int i = 0 ; i < n ; i += 1) {
        printf("Digite um valor para o vetor B(d%/n): ");
        scanf("%d", &vB[i]);
    }
}

void imprimirDoisVetores (int vA[], int vB[], int n) {
    printf("A {");
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d", vA[i]);
        if (i < 20) {
            printf(", ");
        }
    }
    printf("}\n");
    
    printf("B {");
    for (int i = 0 ; i < n ; i += 1) {
        printf("%d", vA[i]);
        if (i < 20) {
            printf(", ");
        }
    }
    printf("}\n");
}

int buscarValor (int vA[], int vB[], int pA, int pB, int n) {
    for (int i = 0 ; i < n ; i += 1) {
        if (vA[i] == pA) {
            return i;
        }
        return -1
    }
    for (int i = 0 ; i < n ; i += 1){
        if (vB[i] == pB) {
            return i;
        }
        return -1
    }
}

int posicaoMAX (int vA[], int vB[], int n) {
    vA[0] = maior;
    for (int i = 0 ; i < n ; i += 1) {
        if (vA[i] > maior)
    }
    
}
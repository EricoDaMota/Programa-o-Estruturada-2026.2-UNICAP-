#include <stdio.h>
#include <string.h>

#define TAM_CHAR 150
#define QTD_PRODUTOS 40

struct Produto {
    int codigo;
    char descricao[TAM_CHAR];
    double valor;
    int estoque;
};

void lerStr(char n[], int tam);
void cadastraProduto (struct Produto v[], int tam, int *pos);



int main() {
    int posicao = 0;
    struct Produto produto[QTD_PRODUTOS];
    for (int i = 0 ; i < QTD_PRODUTOS ; i++) {
        cadastraProduto(produto, QTD_PRODUTOS, &posicao);
    }
}

void lerStr(char n[], int tam) {
    int tamN;
    fgets(n, tam, stdin);
    tamN = strlen(n);
    if (n[tamN - 1] == '\n' && tam > 0) {
        n[tamN - 1] = '\0';
    }
}

void cadastraProduto (struct Produto v[], int tam, int *pos) {
    
    printf("\nDigite o código do novo produto: ");
    scanf("%d", &v[*pos].codigo);

    while(getchar() != '\n')
    
    printf("\nDigite a descrição do novo produto: ");
    lerStr(v[*pos].descricao, tam);
    
    printf("\nDigite o valor do produto: ");
    scanf("%lf", &v[*pos].valor);
    
    printf("\nDigite a quantidade desse produto no estoque: ");
    scanf("%d", &v[*pos].estoque);
    *pos += 1;
}


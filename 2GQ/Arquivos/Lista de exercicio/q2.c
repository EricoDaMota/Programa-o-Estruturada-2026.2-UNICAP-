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
void cadastraProduto (struct Produto v[], int tamC, int qtdP, int *pos);



int main() {
    int posicao = 0;
    struct Produto produto[QTD_PRODUTOS];
    for (int i = 0 ; i < QTD_PRODUTOS ; i++) {
        cadastraProduto(produto, TAM_CHAR, QTD_PRODUTOS, &posicao);
    }
}

void lerStr(char n[], int tam) {
    int tamN;
    fgets(n, tam, stdin);
    tamN = strlen(n);
    if (tamN > 0 && n[tamN - 1] == '\n') {
        n[tamN - 1] = '\0';
    }
}

void cadastraProduto (struct Produto v[], int tamC, int qtdP, int *pos) {
    
    printf("\nDigite o código do novo produto(%d/%d): ", *pos + 1, qtdP);
    scanf("%d", &v[*pos].codigo);

    while(getchar() != '\n');
    
    printf("\nDigite a descrição do novo produto(%d/%d): ", *pos + 1, qtdP);
    lerStr(v[*pos].descricao, tamC);
    
    printf("\nDigite o valor do produto(%d/%d): ", *pos + 1, qtdP);
    scanf("%lf", &v[*pos].valor);
    
    printf("\nDigite a quantidade desse produto no estoque(%d/%d): ", *pos + 1, qtdP);
    scanf("%d", &v[*pos].estoque);
    *pos += 1;
}

int buscaSequencial (struct Produto v[], int x, int qtd){
    for (int i = 0 ; i < qtd ; i++) {
        if (v[i].codigo == x) {
            return i;
        }
    }
    return -1;
}


void alteraValor(struct Produto v[], int qtd) {
    int codQrd, indice;
    double nValor;

    printf("\nDigite o codigo do produto que deseja alterar o valor: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nDigite um codigo de produto valido!");
        printf("\nDigite o codigo do produto que deseja alterar o valor: ");
        scanf("%d", &codQrd);
    }

    printf("\nDigite o novo valor do produto (codigo %d): ", codQrd);
    scanf("%lf", &nValor);

    v[indice].valor = nValor;
}

void verValor (struct Produto v[], int qtd) {
    int codQrd, indice;
    printf("\nDigite o codigo do produto que deseja ver o valor: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nDigite um codigo de produto valido!");
        printf("\nDigite o codigo do produto que deseja ver o valor: ");
        scanf("%d", &codQrd);
    }
    printf("\nProduto(cod: %d): R$%.2f", v[indice].codigo, v[indice].valor);
}

void verQtdEstoque (struct Produto v[], int qtd) {
    int codQrd, indice;
    printf("\nDigite o codigo do produto que deseja ver o número no estoque: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nDigite um codigo de produto valido!");
        printf("\nDigite o codigo do produto que deseja ver o número no estoque: ");
        scanf("%d", &codQrd);
    }
    printf("\nProduto(cod: %d): %d", v[indice].codigo, v[indice].estoque);
}

void vendeProduto (struct Produto v[], int qtd) {
    int codQrd, indice, qtdP, valor, resp;
    printf("\nDigite o codigo do produto que deseja comprar: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nDigite um codigo de produto valido!");
        printf("\nDigite o codigo do produto que deseja ver o número no estoque: ");
        scanf("%d", &codQrd);
    }
    if (v[indice].estoque <= 0) {
        printf("\nNão há mais desse produto no estoque!");
        return;
    }
    printf("\nDigite o número de produtos que deseja comprar: ");
    scanf("%d", &qtdP);
    while (v[indice].estoque < qtdP) {
        printf("\nHá apenas %d desse produto no estoque!", v[indice].estoque);
        printf("\nDigite o número de produtos que deseja comprar: ");
        scanf("%d", &qtdP);
    }
    prinft("Deseja confirmar a compra?(1/0): ");
    if (resp == 1) {
        printf("\nEstoque anterior(cod: %d): %d", codQrd, v[indice].estoque);
        valor = v[indice].valor * qtdP;
        v[indice].estoque -= qtdP;
        printf("\nEstoque atual: %d", v[indice].estoque);
        printf("Valor unitário: %d", v[indice].valor);
        printf("Valor pago total: %d", valor);
    } else {
        return;
    }
}
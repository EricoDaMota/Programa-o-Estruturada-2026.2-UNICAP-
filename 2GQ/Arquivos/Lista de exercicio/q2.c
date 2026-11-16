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
void cadastraProduto(struct Produto v[], int tamC, int qtdP, int *pos);
int buscaSequencial(struct Produto v[], int x, int qtd);
void alteraValor(struct Produto v[], int qtd);
void verValor(struct Produto v[], int qtd);
void verQtdEstoque(struct Produto v[], int qtd);
void vendeProduto(struct Produto v[], int qtd);
void atualizaEstoque(struct Produto v[], int qtd);
void exibeProdutos(struct Produto v[], int qtd);
void exibeSemEstoque(struct Produto v[], int qtd);

int main() {
    int posicao = 0;
    int opcao;

    struct Produto produto[QTD_PRODUTOS];

    do {
        printf("\n========== PAPELARIA ESCOLAR ==========");
        printf("\n1 - Cadastrar produto");
        printf("\n2 - Alterar valor de produto");
        printf("\n3 - Consultar valor de produto");
        printf("\n4 - Consultar quantidade em estoque");
        printf("\n5 - Vender produto");
        printf("\n6 - Atualizar estoque");
        printf("\n7 - Exibir todos os produtos");
        printf("\n8 - Exibir produtos com estoque zero");
        printf("\n0 - Encerrar programa");
        printf("\n=======================================");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                if (posicao < QTD_PRODUTOS) {
                    cadastraProduto(produto, TAM_CHAR, QTD_PRODUTOS, &posicao);
                } else {
                    printf("\nLimite de produtos atingido!");
                }
                break;

            case 2:
                alteraValor(produto, posicao);
                break;

            case 3:
                verValor(produto, posicao);
                break;

            case 4:
                verQtdEstoque(produto, posicao);
                break;

            case 5:
                vendeProduto(produto, posicao);
                break;

            case 6:
                atualizaEstoque(produto, posicao);
                break;

            case 7:
                exibeProdutos(produto, posicao);
                break;

            case 8:
                exibeSemEstoque(produto, posicao);
                break;

            case 0:
                printf("\nEncerrando programa...");
                break;

            default:
                printf("\nOpcao invalida!");
        }

    } while(opcao != 0);

    return 0;
}

void lerStr(char n[], int tam) {
    int tamN;

    fgets(n, tam, stdin);

    tamN = strlen(n);

    if (tamN > 0 && n[tamN - 1] == '\n') {
        n[tamN - 1] = '\0';
    }
}

void cadastraProduto(struct Produto v[], int tamC, int qtdP, int *pos) {

    printf("\nDigite o codigo do novo produto(%d/%d): ", *pos + 1, qtdP);
    scanf("%d", &v[*pos].codigo);

    while(getchar() != '\n');

    printf("\nDigite a descricao do novo produto(%d/%d): ", *pos + 1, qtdP);
    lerStr(v[*pos].descricao, tamC);

    printf("\nDigite o valor do produto(%d/%d): ", *pos + 1, qtdP);
    scanf("%lf", &v[*pos].valor);

    printf("\nDigite a quantidade desse produto no estoque(%d/%d): ", *pos + 1, qtdP);
    scanf("%d", &v[*pos].estoque);

    *pos += 1;
}

int buscaSequencial(struct Produto v[], int x, int qtd) {

    for (int i = 0; i < qtd; i++) {
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

void verValor(struct Produto v[], int qtd) {
    int codQrd, indice;

    printf("\nDigite o codigo do produto que deseja ver o valor: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nDigite um codigo de produto valido!");
        printf("\nDigite o codigo do produto que deseja ver o valor: ");
        scanf("%d", &codQrd);
    }

    printf("\nProduto(cod: %d): R$ %.2f", v[indice].codigo, v[indice].valor);
}

void verQtdEstoque(struct Produto v[], int qtd) {
    int codQrd, indice;

    printf("\nDigite o codigo do produto que deseja ver o numero no estoque: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nDigite um codigo de produto valido!");
        printf("\nDigite o codigo do produto que deseja ver o numero no estoque: ");
        scanf("%d", &codQrd);
    }

    printf("\nProduto(cod: %d): %d", v[indice].codigo, v[indice].estoque);
}

void vendeProduto(struct Produto v[], int qtd) {
    int codQrd, indice, qtdP, resp;
    double valor;

    printf("\nDigite o codigo do produto que deseja comprar: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nDigite um codigo de produto valido!");
        printf("\nDigite o codigo do produto que deseja comprar: ");
        scanf("%d", &codQrd);
    }

    if (v[indice].estoque <= 0) {
        printf("\nNao ha mais desse produto no estoque!");
        return;
    }

    printf("\nDigite o numero de produtos que deseja comprar: ");
    scanf("%d", &qtdP);

    while (qtdP <= 0 || v[indice].estoque < qtdP) {
        printf("\nHa apenas %d desse produto no estoque!", v[indice].estoque);
        printf("\nDigite uma quantidade valida: ");
        scanf("%d", &qtdP);
    }

    if (qtdP < v[indice].estoque) {
        printf("\nA quantidade desejada e inferior ao estoque existente.");
        printf("\nDeseja efetivar a compra e zerar o estoque? (1/0): ");
        scanf("%d", &resp);

        if (resp != 1) {
            printf("\nCompra cancelada!");
            return;
        }

        valor = v[indice].valor * qtdP;
        v[indice].estoque = 0;

    } else {
        valor = v[indice].valor * qtdP;
        v[indice].estoque -= qtdP;
    }

    printf("\nCompra realizada!");
    printf("\nEstoque atual: %d", v[indice].estoque);
    printf("\nValor unitario: R$ %.2f", v[indice].valor);
    printf("\nValor pago total: R$ %.2f", valor);
}

void atualizaEstoque(struct Produto v[], int qtd) {
    int codQrd, indice, nEstoque;

    printf("\nDigite o codigo do produto que deseja atualizar o estoque: ");
    scanf("%d", &codQrd);

    while ((indice = buscaSequencial(v, codQrd, qtd)) == -1) {
        printf("\nCodigo invalido!");
        printf("\nDigite novamente: ");
        scanf("%d", &codQrd);
    }

    printf("\nDigite a nova quantidade em estoque: ");
    scanf("%d", &nEstoque);

    while (nEstoque < 0) {
        printf("\nA quantidade nao pode ser negativa!");
        printf("\nDigite novamente: ");
        scanf("%d", &nEstoque);
    }

    v[indice].estoque = nEstoque;

    printf("\nEstoque atualizado com sucesso!");
}

void exibeProdutos(struct Produto v[], int qtd) {

    if (qtd == 0) {
        printf("\nNenhum produto cadastrado!");
        return;
    }

    printf("\n========== PRODUTOS CADASTRADOS ==========");

    for (int i = 0; i < qtd; i++) {
        printf("\nCodigo: %d", v[i].codigo);
        printf("\nDescricao: %s", v[i].descricao);
        printf("\n");
    }
}

void exibeSemEstoque(struct Produto v[], int qtd) {
    int encontrou = 0;

    printf("\n========== PRODUTOS SEM ESTOQUE ==========");

    for (int i = 0; i < qtd; i++) {

        if (v[i].estoque == 0) {
            printf("\nCodigo: %d", v[i].codigo);
            printf("\nDescricao: %s", v[i].descricao);
            printf("\n");

            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("\nNenhum produto esta com estoque zerado!");
    }
}
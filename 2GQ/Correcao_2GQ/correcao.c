#include <stdio.h>
#include <string.h>

#define TAM_CONTAS 50
#define TAM_OPERACOES 10000

struct Conta {
    int id;
    char cliente[40];
    double saldo;
    double limite;
};

struct Operacao {
    int id;
    int idConta;
    char tipo;
    double valor;
};

int buscaId(struct Conta v[], int tam, int x);

void lerStr(char nome[], int tamChar) {
    int tamLen;

    fgets(nome, tamChar, stdin);
    tamLen = strlen(nome);

    if (tamLen > 0 && nome[tamLen - 1] == '\n') {
        nome[tamLen - 1] = '\0';
    }
}

void cadastraConta(struct Conta v[], int *tam) {

    int id;

    if (*tam >= TAM_CONTAS) {
        printf("Vetor cheio!\n");
        return;
    }

    printf("Digite o ID: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    if (buscaId(v, *tam, id) != -1) {
        printf("ID ja cadastrado!\n");
        return;
    }

    v[*tam].id = id;

    printf("Digite o nome: ");
    lerStr(v[*tam].cliente, 40);

    printf("Digite o saldo: ");
    scanf("%lf", &v[*tam].saldo);

    printf("Digite o limite: ");
    scanf("%lf", &v[*tam].limite);

    if (v[*tam].limite < 0) {
        printf("Limite invalido!\n");
        return;
    }

    (*tam)++;
}

int buscaBinariaNome(struct Conta v[], int tam, char x[]) {

    int inicio = 0;
    int fim = tam - 1;
    int meio;

    while (inicio <= fim) {

        meio = (inicio + fim) / 2;

        if (strcmp(v[meio].cliente, x) == 0) {
            return meio;
        }

        if (strcmp(v[meio].cliente, x) < 0) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

void filtraDevedores(struct Conta vContas[], int tamConta,
                     struct Conta vDevedores[], int *tamDevedores) {

    int i;

    *tamDevedores = 0;

    for (i = 0; i < tamConta; i++) {

        if (vContas[i].saldo < 0) {

            vDevedores[*tamDevedores] = vContas[i];
            (*tamDevedores)++;
        }
    }
}

int realizarSaque(struct Conta vContas[], int tamConta,
                  struct Operacao vOp[], int *tamOp) {

    int id;
    int indice;
    double valor;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);

    indice = buscaId(vContas, tamConta, id);

    if (indice == -1) {
        printf("Conta nao encontrada!\n");
        return 0;
    }

    printf("Digite o valor do saque: ");
    scanf("%lf", &valor);

    if (valor <= 0 || *tamOp >= TAM_OPERACOES) {
        return 0;
    }

    if (vContas[indice].saldo + vContas[indice].limite >= valor) {

        vContas[indice].saldo -= valor;

        vOp[*tamOp].id = *tamOp + 1;
        vOp[*tamOp].idConta = id;
        vOp[*tamOp].tipo = 'S';
        vOp[*tamOp].valor = -valor;

        (*tamOp)++;

        return 1;
    }

    return 0;
}

void extrato(struct Conta vContas[], int tamConta,
             struct Operacao vOp[], int tamOp) {

    int id;
    int indice;
    int posicoes[5];
    int qtd = 0;
    int i;
    double saldoAnterior;

    printf("Digite o ID da conta: ");
    scanf("%d", &id);

    indice = buscaId(vContas, tamConta, id);

    if (indice == -1) {
        printf("Conta nao encontrada!\n");
        return;
    }

    for (i = 0; i < tamOp; i++) {

        if (vOp[i].idConta == id) {

            if (qtd < 5) {
                posicoes[qtd] = i;
                qtd++;
            }
            else {
                posicoes[0] = posicoes[1];
                posicoes[1] = posicoes[2];
                posicoes[2] = posicoes[3];
                posicoes[3] = posicoes[4];
                posicoes[4] = i;
            }
        }
    }

    saldoAnterior = vContas[indice].saldo;

    for (i = 0; i < qtd; i++) {
        saldoAnterior -= vOp[posicoes[i]].valor;
    }

    printf("\nCLIENTE: %s\n", vContas[indice].cliente);
    printf("ID: %d\n", id);
    printf("\nSaldo Anterior: %.2lf\n", saldoAnterior);

    for (i = 0; i < qtd; i++) {

        saldoAnterior += vOp[posicoes[i]].valor;

        printf("\nID: %d", vOp[posicoes[i]].id);
        printf("\nOperacao: %c", vOp[posicoes[i]].tipo);

        if (vOp[posicoes[i]].valor < 0) {
            printf("\nValor: %.2lf", -vOp[posicoes[i]].valor);
        }
        else {
            printf("\nValor: %.2lf", vOp[posicoes[i]].valor);
        }

        printf("\nSaldo: %.2lf\n", saldoAnterior);
    }

    printf("\nSaldo Atual: %.2lf\n", vContas[indice].saldo);
}
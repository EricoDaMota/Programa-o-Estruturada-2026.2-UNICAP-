#include <stdio.h>
#include <string.h>

#define TAM_NOME 50

void lerStr(char str[], int tamMax);

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso;
    double altura;
};

int main() {
    struct Pessoa pessoa;
    printf("Digite o seu nome: \n");
    lerStr(pessoa.nome, TAM_NOME);
    printf("Digite a sua idade: \n");
    scanf("%d", &pessoa.peso);
    printf("Digite o seu peso: \n");
    scanf("%lf", &pessoa.peso);
    printf("Digite sua altura: \n");
    scanf("%lf", &pessoa.altura);
    printf("%s, %d, %2.lfkg, %2.lfm", pessoa.nome, pessoa.idade, pessoa.peso, pessoa.altura);
    return 0;
}

void lerStr (char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\0') {
        str[tam - 1] = '\0';
    }
}
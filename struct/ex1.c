#include <stdio.h>
#include <string.h>
#define TAM 50

struct Horario {
    double hora;
    double minuto;
    double segundo;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    int data;
    int horario;
    char compromisso[TAM];
};

struct Pessoa {
    char nome[TAM];
    int idade;
    char endereco[TAM];
};

int main() {
    struct Pessoa pessoa;
    printf("Digite o nome da pessoa: ");
    fget(pessoa.nome, TAM, stdin);
    printf("Digite a idade da pessoa: ");
    fget(pessoa.idade, TAM, stdin);
    printf("Digite o endereço da pessoa: ");
    fget(pessoa.endereco, TAM, stdin);
    armazenarInfo(pessoa, TAM);
    return 0;
}


int TamChar (char v[], int tam) {
    int i = 0;
    while (i < 50 && v[tam] != '\0') {
        i++;
    }
    return i;
}




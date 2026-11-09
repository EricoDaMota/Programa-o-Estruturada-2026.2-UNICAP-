#include <stdio.h>
#include <string.h>
#include <math.h>
#define TAM 50

struct Horario {
    int hora;
    int minutos;
    int segundos;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char compromisso[TAM];
};

struct Pessoa {
    char nome[TAM];
    int idade;
    char endereco[TAM];
};

struct Vetor {
    double x;
    double y;
    double z;
};

struct Polar {
    double r;
    double a;
};

struct Cartesiana {
    double x; 
    double y;
};

int main() {
    struct Pessoa p;    
}

struct Pessoa preencherValores (struct Pessoa p, int tam) {
    printf("Digite o nome da pessoa: ");
    fget(p.nome, tam, stdin);
    printf("Digite a idade: ");
    fget(p.idade, tam, stdin);
    printf("Digite o endereço: ");
    fget(p.endereco, tam, stdin);
    return p;
}
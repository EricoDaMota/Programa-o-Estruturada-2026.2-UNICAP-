#include <stdio.h>
#include <string.h>

#define TAM 50

struct Horario{
    double hora;
    double minutos;
    double segundos;
};

struct Data{
    double dia;
    double mes;
    double ano;
};

struct compromisso{
    double data;
    double horario;
    char compromisso[TAM];
};

struct Vetor{
    double x;
    double y;
    double z;
};


int main() {

}

int informacoesP(struct Pessoa p, TAM) {
    printf("Digite o nome da pessoa: ");
    fget(p.nome, TAM, stdin);
    printf("Digite a idade da pessoa: ");
    fget(p.idade, TAM, stdin);
    printf("Digite o endereço da pessoa: ");
    fget(endereco, TAM, stdin);
}


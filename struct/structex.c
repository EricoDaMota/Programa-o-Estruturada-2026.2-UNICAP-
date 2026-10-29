#include <stdio.h>
#include <string.h>
#include <math.h>

#define TAM 50

struct Horario {
    int hora;
    int minuto;
    int segundo;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char texto[TAM];
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

struct Cartesiano {
    double x;
    double y;
};

struct Vetor somarVetores(struct Vetor v1, struct Vetor v2);
struct Cartesiano polarParaCartesiano(struct Polar p);

int main() {
    struct Pessoa pessoa;
    printf("=== CADASTRO DE PESSOA ===\n");
    printf("Digite o nome da pessoa: ");
    fgets(pessoa.nome, TAM, stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa.idade);
    getchar();

    printf("Digite o endereço da pessoa: ");
    fgets(pessoa.endereco, TAM, stdin);
    pessoa.endereco[strcspn(pessoa.endereco, "\n")] = '\0';

    printf("\nDados cadastrados:\nNome: %s | Idade: %d | Endereço: %s\n\n", pessoa.nome, pessoa.idade, pessoa.endereco);

    printf("=== SOMA DE VETORES NO R3 ===\n");
    struct Vetor v1 = {1.0, 2.0, 3.0};
    struct Vetor v2 = {4.0, 5.0, 6.0};
    struct Vetor soma = somarVetores(v1, v2);
    printf("Soma dos vetores: (%.2lf, %.2lf, %.2lf)\n\n", soma.x, soma.y, soma.z);

    printf("=== CONVERSÃO POLAR PARA CARTESIANA ===\n");
    struct Polar p;
    printf("Digite o raio (r): ");
    scanf("%lf", &p.r);
    printf("Digite o argumento em radianos (a): ");
    scanf("%lf", &p.a);

    struct Cartesiano c = polarParaCartesiano(p);
    printf("Coordenadas Cartesianas: x = %.2lf, y = %.2lf\n", c.x, c.y);

    return 0;
}

struct Vetor somarVetores(struct Vetor v1, struct Vetor v2) {
    struct Vetor resultado;
    resultado.x = v1.x + v2.x;
    resultado.y = v1.y + v2.y;
    resultado.z = v1.z + v2.z;
    return resultado;
}

struct Cartesiano polarParaCartesiano(struct Polar p) {
    struct Cartesiano c;
    c.x = p.r * cos(p.a);
    c.y = p.r * sin(p.a);
    return c;
}
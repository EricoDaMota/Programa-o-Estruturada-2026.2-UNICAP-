#include <stdio.h>

#define TAM_NOMES 20
#define TAM_ESTADOS 27

struct Estados {
    char nomeEstado[TAM_NOMES];
    int numeroVeiculos;
    int numeroAcidentes;
};

int main() {
    struct Estados estado[TAM_ESTADOS];
    preencherVetor(&estado, TAM_ESTADOS);
    maiorEMenor(&estado, TAM_ESTADOS);
}

void preencherVetor (struct Estados * e[], int tamE) {
    for (int i = 0 ; i < tamE ; i++) {
        printf("Digite o nome do estado: ");
        fgets(e[i]->nomeEstado, tamE, stdin);
        printf("Digite o número de veículos de cada estado: ");
        fgets(e[i]->numeroVeiculos, tamE, stdin);
        printf("Digite o número de acidentes de carro em cada estado: ");
        fgets(e[i]->numeroAcidentes, tamE, stdin);
    }
}

void maiorEMenor (struct Estados * e[], int tamE) {
    int indiceDMaior;
    int indiceDMenor;
    int maior;
    int menor;
    for (int i = 0 ; i < tamE ; i++) {
        if(maior < e[i]->numeroAcidentes) {
            maior = e[i]->numeroAcidentes;
            indiceDMaior = i;
            
        }
        if(menor > e[i]->numeroAcidentes) {
            menor = e[i]->numeroAcidentes;
            indiceDMenor = i;

        }
    }
    printf("Nome do estado com maior N acidentes: &s\nNúmero de acidentes: &d", e[indiceDMaior]->nomeEstado, e[indiceDMaior]->numeroAcidentes);
    printf("Nome do estado com menor N acidentes: &s\nNúmero de acidentes: &d", e[indiceDMenor]->nomeEstado, e[indiceDMenor]->numeroAcidentes);
}
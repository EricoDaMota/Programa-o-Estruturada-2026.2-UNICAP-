#include <stdio.h>

#define TAM_NOMES 40
#define TAM_ESTADOS 2

struct Estados {
    char nomeEstado[TAM_NOMES];
    int numeroVeiculos;
    int numeroAcidentes;
};

void preencherVetor(struct Estados e[], int tamN, int tamE);
void maiorEMenor(struct Estados e[], int tamE);
void lerStr(char e[], int tamN);

int main() {
    struct Estados estado[TAM_ESTADOS];
    preencherVetor(estado, TAM_NOMES, TAM_ESTADOS);
    maiorEMenor(estado, TAM_ESTADOS);
}

void preencherVetor (struct Estados e[], int tamN, int tamE) {
    for (int i = 0 ; i < tamE ; i++) {
        printf("Digite o nome do estado: ");
        fgets(e[i].nomeEstado, tamN, stdin);
        lerStr(e[i].nomeEstado, tamN);
        printf("Digite o número de veículos de cada estado: ");
        scanf("%d", &e[i].numeroVeiculos);
        printf("Digite o número de acidentes de carro em cada estado: ");
        scanf("%d", &e[i].numeroAcidentes);
        while (getchar() != '\n');
    }
}

void maiorEMenor (struct Estados e[], int tamE) {
    int indiceDMaior = 0;
    int indiceDMenor = 0;
    int maior = e[0].numeroAcidentes;
    int menor = e[0].numeroAcidentes;
    for (int i = 1 ; i < tamE ; i++) {
        if(maior < e[i].numeroAcidentes) {
            maior = e[i].numeroAcidentes;
            indiceDMaior = i;
            
        }
        if(menor > e[i].numeroAcidentes) {
            menor = e[i].numeroAcidentes;
            indiceDMenor = i;

        }
    }
    printf("Nome do estado com maior N acidentes: %s\nNúmero de acidentes: %d\n", e[indiceDMaior].nomeEstado, e[indiceDMaior].numeroAcidentes);
    printf("Nome do estado com menor N acidentes: %s\nNúmero de acidentes: %d\n", e[indiceDMenor].nomeEstado, e[indiceDMenor].numeroAcidentes);
}

void lerStr (char e[], int tamN) {
    int i = 0;
    while(i < tamN && e[i] != '\n' && e[i] != '\0') {
        i++;
    }
    if(e[i] == '\n') {
        e[i] = '\0';
    }
}
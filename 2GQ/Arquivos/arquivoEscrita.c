#include <stdio.h>

#define TAM 255

int main() {
    char frase[TAM];
    FILE *arq = fopen("teste.txt", "at");
    if (!arq) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    printf("Digite uma frase para ser guardada!\n");
    lerStr(frase, TAM);
    //salva a frase digitada dentro de ASPAS
    status = fprintf(arq, "%s"\)
}


void lerStr (char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\0') {
        str[tam - 1] = '\0';
    }
}
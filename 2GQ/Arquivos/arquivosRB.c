#include <stdio.h>

int main() {
    FILE *arq;
    int status;
    double numeros[3];
    arq = fopen("teste.bin", "rb");
    if (arq == NULL) {
        printf("Não foi possível abri o arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    // status = fread(numeros, sizeof(double), 3, arq);
    // if (status == 3) {
    //     printf("Os números lidos foram: %d - %d - %d\n", numeros[0], numeros[1], numeros[3]);
    // }
    // status = fclose(arq);
    // if (status == 0) {
    //     printf("Arquivo fechado com sucesso!\n");
    // }else {
    //     printf("Erro no fechamento do arquivo com o código %d\n", status);
    // }

    status = fread(numeros, sizeof(double), 1, arq);
    while (!feof(arq)) {
        if (status == 1) {
            printf("%f \t", num);
        } else {
            printf("Erro ao ler um número, status = %d\n", status);
            break;
        }
        status = fclose(arq);
        if (status == 0) {
            printf("Arquivo fechado com sucesso!\n");
        }else {
            printf("Erro no fechamento do arquivo com o código %d\n", status);
    }
    return 0;
}
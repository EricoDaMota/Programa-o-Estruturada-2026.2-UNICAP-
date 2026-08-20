#include <stdio.h>
#define QTD_MAX 5
int main() {
    int num, soma = 0, qtd = 0;
    int numeros[QTD_MAX];
    double media;
    printf("digite o valor da nota: ");
    scanf("%d", &num);
    
    while (num > 0) {
        numeros[qtd] = num;
        soma += num;
        qtd += 1;
        if (qtd >= QTD_MAX){
            printf("Quantidade máxima de valores atingida\n");
            break;
        }
    printf("digite o valor da nota(< 0 para finalizar): ");
    scanf("%d", &num);
    }
    if (qtd > 0) {
        media = (double) soma / (double) qtd;
        printf("Foram digitados %d valores e a média é %f\n", qtd, media);
    }
}
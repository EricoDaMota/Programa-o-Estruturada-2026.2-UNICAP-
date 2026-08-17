#include <stdio.h>
#define QTD_MAX_VALORES 5
int main () {
    
    int num, soma = 0, qtd = 0, qtd_acimaM = 0;
    int numeros[QTD_MAX_VALORES];
    double media;

    prinff("Digite um valor inteiro positivo: ");
    scanf("%d", &num);
    while (num > 0) {
        numeros[qtd] = num;
        soma += num;
        qtd += 1;
        if (qtd > QTD_MAX_VALORES) {
            printf("Digite um valor inteiro inteiro positivo (<= 0 para finalizar): ");
            scanf("%d", &num);
        }
        else {
            printf("Nenhum número válido foi digitado!\n");
        }
        return 0;
    }

}
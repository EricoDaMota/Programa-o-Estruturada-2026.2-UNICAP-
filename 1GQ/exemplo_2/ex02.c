#include <stdio.h>

#define IDADE_MAXIMA 130
#define IDADE_MINIMA 0
#define ANO_ATUAL 2026

int main() {
    int ano;
    printf("Digite o ano que você nasceu: ");
    scanf("%d", &ano);
    int idade = ANO_ATUAL - ano;
    while (idade < IDADE_MINIMA || idade > IDADE_MAXIMA) {
    printf("Digite o ano que você nasceu: ");
    }
    printf("Você tem aproximadamente %d anos\n", idade);
    return 0;
}
#include <stdio.h>
int main() {
    char nome[50];
    int idade;
    
    printf("Qual é o seu nome? ");
    scanf("%s", nome);
    printf("Qual é a sua idade? ");
    scanf("%d", &idade);
    printf("Prazer %s, com a idade de %d anos, muito bom te conhecer!", nome, idade);

    return 0;
}


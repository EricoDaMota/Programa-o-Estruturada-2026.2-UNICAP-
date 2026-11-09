#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 3

int main() {
    for (int i = 0 ; i < QTD_LINHAS ; i += 1) {
        for(int j = 0 ; j < QTD_COLUNAS ; j += 1) {
            printf("i = %d - j = %d\n", i, j);
        }
    }
    return 0;
}
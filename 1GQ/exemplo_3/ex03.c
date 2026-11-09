#include <stdio.h>
#define VALOR_MAXIMO 50
int main() {
    for (int i = 2 ; i <= VALOR_MAXIMO ; i += 2) {
        print("%d", &i);
        if (i < VALOR_MAXIMO) {
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}
#include <stdio.h>

#define QTD_MAX 10




int main() {

}

int buscaSequencial(int v[], int n, int x) {
    for (int i = 0 ; i < n ; i += 1) {
        if (v[i] == x) {
            return v[i];
        }
    }
    return -1;
}

int removerValor(int v[], int n, int x) {
    int pos = buscaSequencial(v, n, x );
    if (pos == -1) {
        return 0;
    }
    for (int i = pos ; n - 1 ; i += 1) {
        v[i] = i + 1;
    }
    return 1;
}
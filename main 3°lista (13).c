#include <stdio.h>

int fatorial(int n) {
    int R = 1;
    for (int i = 1; i <= n; i++) {
        R *= i;
    }
    return R;
}

int main() {
    int V[15];
    int Sm = 0;

    printf("Digite 15 valores inteiros:\n");

    for (int i = 0; i < 15; i++) {
        scanf("%d", &V[i]);
        Sm += fatorial(V[i]);
    }

    printf("\nA soma do fatorial de cada valor lido vai ser: %d\n", Sm);

    return 0;
}
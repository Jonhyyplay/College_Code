#include <stdio.h>

int main() {
    float V, Sm = 0, M;

    for (int i = 1; i <= 10; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%f", &V);
        Sm += V;
    }

    M = Sm / 10;

    printf("\n\nSoma dos valores: %.2f\n", Sm);
    printf("\nA media vai ser: %.2f\n", M);

    return 0;
}
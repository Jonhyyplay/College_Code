#include <stdio.h>

int main() {
    int i, Qnt;
    float V, Sm = 0, M;
    
    printf ("Digite a quantidade de valores que deseja somar: ");
    scanf ("%d", &Qnt);

    for (i = 1; i <= Qnt; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%f", &V);
        if (V < 0){
            printf ("\nInvalidado, valor negativo inserido\n");
            break;
        }
        Sm += V;
    }

    M = Sm / (i-1);

    printf("\nSoma: %.2f\n", Sm);
    printf("A Media vai ser: %.2f\n", M);

    return 0;
}
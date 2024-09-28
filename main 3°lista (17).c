#include <stdio.h>

int main() {
    int V, Sm = 0, count = 0;
     float M;
    
    for (V = 50; V <= 70; V++) {
        if (V % 2 == 0){
            Sm += V;
            count++;
        }

    }
    M = Sm / count;

    printf("\nSoma dos pares entre 50 e 70: %d\n", Sm);
    printf("A Media vai ser: %.1f\n", M);

    return 0;
}
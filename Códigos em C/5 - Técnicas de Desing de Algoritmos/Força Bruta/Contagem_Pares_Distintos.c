#include <stdio.h>
#include <stdlib.h>

//Estrutura inspirada no do Números Duplicados
int main() {
   int qntd;
    int pares = 0;

    printf("\n\nDigite a quantidade de números: ");
    scanf("%d", &qntd);

    int *array = malloc(qntd * sizeof(int));

    printf("\n\nDigite os valores desse array: \n");
    for (int k = 0; k < qntd; k++) {
        scanf("%d", &array[k]);
    }

    for (int i = 0; i < qntd - 1; i++) {
        for (int j = i + 1; j < qntd; j++){
            
            if (array[i] != array[j]) {
                pares++;
            }
        }
    }
    if (pares) {
        printf("\n\nHá %d pares distintos", pares);
    }else {
        printf("\n\nNão há pares distintos");
    }

    free(array);

    return EXIT_SUCCESS;
}
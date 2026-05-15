#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho, v_alvo;

    printf("\n\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = malloc(tamanho * sizeof(int));

    printf("\n\nDigite os valores do vetor:\n");
    for (int k = 0; k < tamanho; k++) {
        scanf("%d", &vetor[k]);
    }

    printf("\n\nDigite o valor alvo: ");
    scanf("%d", &v_alvo);

    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] + vetor[j] == v_alvo) {
                printf("\n\nAchou um par: %d + %d = %d\n", vetor[i], vetor[j], v_alvo);
                encontrou = 1;
            }
        }
    }
    if (!encontrou) {
        printf("\n\nNenhum par encontrado que some %d.\n", v_alvo);
    }

    free(vetor);
    return EXIT_SUCCESS;
}
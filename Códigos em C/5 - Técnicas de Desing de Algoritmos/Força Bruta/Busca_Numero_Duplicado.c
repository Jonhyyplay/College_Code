#include <stdio.h>
#include <stdlib.h>

//Estrutura inspirada no do Par de Soma
int main() {
   int quantidade;

    printf("\n\nDigite a quantidade de números: ");
    scanf("%d", &quantidade);

    int *array = malloc(quantidade * sizeof(int));

    printf("\n\nDigite os valores dessa array: \n");
    for (int k = 0; k < quantidade; k++) {
        scanf("%d", &array[k]);
    }

    int duplicado = 0;

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i + 1; j < quantidade; j++){
            if (array[i] == array[j]) {
                printf("\n\nO número %d está duplicado", array[i]);
                duplicado = 1;
            }
        }
    }
    if (!duplicado) {
        printf("\n\nNenhum número duplicado encontrado.\n");
    }

    free(array);

    return EXIT_SUCCESS;
}
#include <stdio.h>

int main() {
    int B, E, R = 1;

    printf("Digite a base: ");
    scanf("%d", &B);

    printf("Digite o expoente: ");
    scanf("%d", &E);

    // Verifica se o expoente é negativo
    if (E < 0) {
        printf("Erro: O expoente deve ser um valor inteiro positivo.\n");
        return 0;
    }

    // Calcula a potência
    for (int i = 0; i < E; i++) {
        R *= B;
    }

    printf("\nO resultado de %d elevado a %d vai ser %d\n", B, E, R);

    return 0;
}
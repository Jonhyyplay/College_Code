#include <stdio.h>

int main() {
    char nome[50];
    float largura, comprimento, area, a_total = 0;
    char continuar;

    do {
        printf("Digite o nome do comodo: ");
        scanf("%s", nome);

        printf("\nDigite a largura do comodo em metros: ");
        scanf("%f", &largura);

        printf("Digite o comprimento do comodo em metros: ");
        scanf("%f", &comprimento);

        area = largura * comprimento;
        printf("A area do comodo %s e: %.2f metros quadrados\n", nome, area);

        a_total += area;

        printf("\nDeseja continuar calculando novos comodos? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    printf("\nA area total da residencia e: %.2f metros quadrados\n", a_total);

    return 0;
}
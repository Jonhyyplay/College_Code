#include <stdio.h>
#include <stdlib.h>

typedef struct {   //Definição da estrutura "Atividade"
    char nome[50];
    int inicio;
    int fim;
} Atividade;

int main () {
    
    int n;
    printf("Digite o número de atividades: ");
    scanf("%d", &n);

    Atividade agenda[n];
    for (int i = 0; i < n; i++) {
        printf("Atividade %d - Nome: ", i+1);
        scanf("%s", agenda[i].nome);
        printf("Início: ");
        scanf("%d", &agenda[i].inicio);     //se você tentar inserir uma atividade cujo horário de início seja menor que o término da última selecionada, ela será ignorada.
        printf("Fim: ");
        scanf("%d", &agenda[i].fim);
    }

    // Aqui ordena as atividades pelo horário de término
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (agenda[j].fim > agenda[j+1].fim) {
                Atividade temp = agenda[j];
                agenda[j] = agenda[j+1];
                agenda[j+1] = temp;
            }
        }
    }

    printf("\nAtividades selecionadas:\n");
    int ultimaFim = -1;
    for (int i = 0; i < n; i++) {
        if (agenda[i].inicio >= ultimaFim) {
            printf("%s (Início: %d, Fim: %d)\n", agenda[i].nome, agenda[i].inicio, agenda[i].fim);
            ultimaFim = agenda[i].fim;
        }
    }

    return (EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //Pra usar true e false

int main() {
    int n_elementos;
    printf("Digite a quantidade de números no conjunto: ");
    scanf("%d", &n_elementos);

    // Aloca memória para o array de números com um ponteiro simples.
    int *conjunto = malloc(n_elementos * sizeof(int));                            //Isso para que não tenha que colocar valores estáticos em um array
    if (conjunto == NULL) return 1; // Verifica falha na alocação

    printf("Digite os %d números do conjunto:\n", n_elementos);
    for (int i = 0; i < n_elementos; i++) {
        scanf("%d", &conjunto[i]);
    }

    int soma_alvo;
    printf("Digite o valor da soma alvo: ");
    scanf("%d", &soma_alvo);

    int n_linhas = n_elementos + 1;
    int n_colunas = soma_alvo + 1;

    // Aloca a tabela dp como um único array grande
    bool *dp = (bool*)malloc(n_linhas * n_colunas * sizeof(bool));
    if (dp == NULL) {
        free(conjunto); // Libera memória já alocada antes de sair
        return 1;
    }

    // Preenchimento da tabela
    for (int i = 0; i < n_linhas; i++) {
        for (int j = 0; j < n_colunas; j++) {
            // Caso base 1 é se a soma 0 sempre possível 
            if (j == 0) {
                dp[i * n_colunas + j] = true;
            }
            // Caso base 2 é se com 0 elementos, nenhuma soma > 0 é possível
            else if (i == 0) {
                dp[i * n_colunas + j] = false;
            }

            else {
                int num_atual = conjunto[i - 1]; // Pega o número atual do conjunto
                
                // Opção de não incluir o número atual.
                dp[i * n_colunas + j] = dp[(i - 1) * n_colunas + j];

                // Opção de incluir o número atual, caso possível
                if (j >= num_atual) {
                    // A resposta será 'true' se a Opção 1 OU a Opção 2 for 'true'.
                    dp[i * n_colunas + j] = dp[i * n_colunas + j] || dp[(i - 1) * n_colunas + (j - num_atual)];
                }
            }
        }
    }

    // O resultado final está na célula do canto inferior direito da tabela
    bool resultado = dp[(n_linhas - 1) * n_colunas + (n_colunas - 1)];

    if (resultado) {
        printf("\nVerdadeiro: Existe pelo menos um subconjunto com a soma %d.\n", soma_alvo);
    } else {
        printf("\nFalso: Não existe um subconjunto com a soma %d.\n", soma_alvo);
    }

    // Libera toda a memória alocada
    free(conjunto);
    free(dp);

    return 0;
}
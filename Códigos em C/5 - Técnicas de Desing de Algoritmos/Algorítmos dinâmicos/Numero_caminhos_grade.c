#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;

    do {
        printf("Digite os valores das linhas e colunas da grade: ");
        scanf("%d %d", &m, &n);
    
        if (m <= 0 || n <= 0) {
            printf("\nAcredito que as dimensões devem ser positivas. Tente novamente!\n\n");
        }

    } while (m <= 0 || n <= 0); 

    if (m == 1 || n == 1) {
        printf("\nPara uma grade %d x %d, existe 1 caminho único.\n", m, n);
        return 0;
    }

    unsigned long long **dp = (unsigned long long **)malloc(m * sizeof(unsigned long long *));
    if (dp == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        dp[i] = (unsigned long long *)malloc(n * sizeof(unsigned long long));
        if (dp[i] == NULL) {
            printf("Falha na alocação de memória.\n");
            return 1;
        }
    }

    for (int i = 0; i < m; i++) {
        dp[i][0] = 1; 
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1; 
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    unsigned long long resultado = dp[m - 1][n - 1];
    printf("\nPara uma grade %d x %d, existem %llu caminhos únicos.\n", m, n, resultado);

    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return EXIT_SUCCESS;
}
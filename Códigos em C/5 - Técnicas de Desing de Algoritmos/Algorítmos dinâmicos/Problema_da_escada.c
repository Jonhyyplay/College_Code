#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_degraus;

    printf("Digite o número de degraus que a escada terá: \n");
    scanf("%d", &n_degraus);
/*
    Usei o estilo Bottom-Up para torná-lo Dinâmico.
    Casos base: 
      - Para 1 degrau ou nenhum → 1 maneira
      - Para 2 degraus → 1 maneira
    Para n >= 3, o número de maneiras segue a lógica de Fibonacci,
    sendo calculado iterativamente pela soma dos 2 últimos resultados.
    Como o algoritmo usa apenas duas variáveis auxiliares,
    garante tempo O(n) e espaço O(1).
*/
    if (n_degraus <= 1){
        
        printf("\nPara 1 ou nenhum degraus, existe 1 maneira de subir a escada");
        return 0;
    
    } else if (n_degraus == 2){
        
        printf("\nPara 2 degraus, existe 2 maneira de subir a escada");
        return 0;
    
    } else{

    int penultimo = 1; 
    int anterior = 2;  
    int maneiras_atuais;

    for (int i = 3; i <= n_degraus; i++) {

        maneiras_atuais = anterior + penultimo;
        
        penultimo = anterior;
        anterior = maneiras_atuais;
    }

    printf("\n\nPara %d degraus, existem %d maneiras diferentes de subir.\n", n_degraus, maneiras_atuais);
}
    return EXIT_SUCCESS;
}
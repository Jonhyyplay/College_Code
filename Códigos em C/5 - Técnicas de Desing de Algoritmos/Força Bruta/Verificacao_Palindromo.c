#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Serve para medir o tamanho da string

int main() {
    char string[100];

    printf("\n\nDigite uma string: ");
    scanf("%s", string);

    int comprimento = strlen(string);
    int palindromo = 1; //Assumido que é um palíndromo, até provar o contrário
    
    for (int i = 0; i < comprimento / 2; i++) {
        
        if (string[i] != string[comprimento - 1 - i]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo) {
        printf("\n\nA string %s é um palíndromo", string);
    }else {
        printf("\n\nA string %s não é um palíndromo", string);
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Serve para medir o tamanho da string

int main() {
    char str1[100], str2[100];
    int usado[100] = {0}; // Marca se o caractere de str2 já foi usado

    printf("\nDigite a primeira string: ");
    scanf("%s", str1);

    printf("\nDigite a segunda string: ");
    scanf("%s", str2);

    int comprimento1 = strlen(str1);
    int comprimento2 = strlen(str2);

    int anagrama = 1;

    if (comprimento1 != comprimento2) {
        anagrama = 0;
    } else {
        for (int i = 0; i < comprimento1; i++) {
            int encontrou = 0;
            for (int j = 0; j < comprimento2; j++) {
                if (str1[i] == str2[j] && !usado[j]) {
                    usado[j] = 1; // Marca como usado
                    encontrou = 1;
                    break;
                }
            }
            if (!encontrou) {
                anagrama = 0;
                break;
            }
        }
    }

    if (anagrama) {
        printf("\nSão anagramas!");
    } else {
        printf("\nNão são anagramas!");
    }

    return EXIT_SUCCESS;
}
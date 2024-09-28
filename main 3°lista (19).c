#include <stdio.h>
int main(){
    int V, maior, menor, i = 1;

    printf ("Digite o valor %d: ", i);
    scanf ("%d", &V);

    maior = menor = V;

    while (V >= 0){
        i++;
        printf ("Digite o valor %d: ", i);
        scanf ("%d", &V);

        if (V > maior){
            maior = V;
        } 
        if (V < menor){
            menor = V;
        }

        if (V < 0){
            break;
        }
    }

    printf ("\nMaior valor inserido: %d", maior);
    printf ("\nMenor valor inserido: %d", menor);

    return 0;
}
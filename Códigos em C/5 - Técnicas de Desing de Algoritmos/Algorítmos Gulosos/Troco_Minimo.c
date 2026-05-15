#include <stdio.h>
#include <stdlib.h>

void saca(int valor){
    int notas[8] = {200,100,50,20,10,5,2,1}; //Valor 200 é um extra
    int quantidade[8] = {0};

    for (int i = 0; i < 8; i++){
        if (valor >= notas[i]){
            quantidade[i] = valor / notas[i];
            valor %= notas[i];
        }
    }

    for (int i = 0; i < 8; i++){
        printf("R$ %d,00 -> %d\n",notas[i],quantidade[i]);
    }

}

int main() {
    saca(5542);
    
    return (EXIT_SUCCESS);
}

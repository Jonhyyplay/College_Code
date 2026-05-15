#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //Pra usar true e false

#define TAM 4

bool resolverLabirinto (int labirinto [TAM][TAM], int x, int y, int n) {  
    
    if (x == n - 1 && y == n - 1 && labirinto[x][y] == 0) {
        return true;
    }

    if (x < 0 || x >= n || y < 0 || y >= n || labirinto[x][y] == 1 || labirinto[x][y] == 2) {
        return false;
    }

    labirinto[x][y] = 2;

    // Tenta ir para a Direita
    if (resolverLabirinto(labirinto, x, y + 1, n)) 
        return true;
    // Tenta ir para a Esquerda
    if (resolverLabirinto(labirinto, x, y - 1, n)) 
        return true;
    // Tenta ir para Baixo
    if (resolverLabirinto(labirinto, x + 1, y, n)) 
        return true;
    // Tenta ir para Cima
    if (resolverLabirinto(labirinto, x - 1, y, n)) 
        return true;

  labirinto[x][y] = 0; // Apaga a marcação
    return false;// Caminho falhou
}

int main() {
    int n = TAM;
    int labirinto[TAM][TAM] = { //Definindo o labirinto (estrutura)
        {0, 1, 1, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 0},
    }; 
    
    if(resolverLabirinto(labirinto, 0, 0, n)) {
        printf("\nSim\n\n");
    } else {
        printf("\nNão\n\n");
    } 
    
    return (EXIT_SUCCESS);
}
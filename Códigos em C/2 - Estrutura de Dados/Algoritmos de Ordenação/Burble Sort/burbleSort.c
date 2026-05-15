#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int vetor[TAM] = {5,4,3,2,1};
int passos = 0;


void listar(int v[], int tamanho);

void bubbleSort(int v[], int tamanho){
  int temp;
  int estaOrdenado;

  //for (int j = 0; j < tamanho-1; j++){
  for (int j = 0; j < tamanho; j++){
    //estaOrdenado = 1;
    //for (int i = 0; i < tamanho - 1 - j; i++){
    for (int i = 0; i < tamanho - 1; i++){
      //passos++;
      if (v[i] > v[i + 1]){
        //estaOrdenado = 0;
        temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
       // listar(vetor, TAM);
      }
    }
    //if (estaOrdenado)
      //return;
  }
}

void listar(int v[], int tamanho){
  int i;
  printf("\n\nListando\n");
  for (i = 0; i < tamanho; i++){
    printf("%d ", v[i]);
  }
}

int main(int argc, char** argv) {

  listar(vetor, TAM);
  bubbleSort(vetor, TAM);
  listar(vetor, TAM);

  printf("\nPassos: %d\n",passos);


 
  return (EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int vetor[TAM] = {4,1,3,5,2};
int passos = 0;

void listar(int v[], int tamanho);

void merge(int v[], int inicio,int meio, int fim){ //função pra intercalar duas subpartes ordenadas do vetor
    int i, j, k, n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esq = malloc(n1 *sizeof(int));
    int *dir = malloc(n2 *sizeof(int));

    for (i = 0; i < n1; i++)
        esq[i] = v[inicio + i];
    for (j = 0; j < n2; j++)
        dir[j] = v[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while(i < n1 && j < n2){
        if (esq[i] <= dir[j])
            v[k++] = esq[i++];
        else
            v[k++] = dir[j++];
    }

    while(i < n1)
        v[k++] = esq[i++];
    while(j < n2)
        v[k++] = dir[j++];

    free(esq);
    free(dir);
}

void mergeSort(int v[], int inicio, int fim){ // função principal
    
    if(inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }

}

void listar(int v[], int tamanho){
  int i;
  printf("\n\nListando\n");
  for (i = 0; i < tamanho; i++){
    printf("%d ", v[i]);
  }
}

int main() {

  listar(vetor, TAM);
  mergeSort(vetor, 0, TAM - 1);
  listar(vetor, TAM);

  printf("\nPassos: %d\n",passos);
 
  return (EXIT_SUCCESS);
}
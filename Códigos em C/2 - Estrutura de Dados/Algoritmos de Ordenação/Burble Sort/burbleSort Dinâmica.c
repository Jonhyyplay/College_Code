#include <stdio.h>
#include <stdlib.h>

typedef struct SFila {
  int dado;
  struct SFila * next;
} TFila;
 
 //Sentinela
TFila * fila = NULL;

void enqueue(int informacao){

  TFila * ultimo;
  TFila * novo;
  novo = malloc(sizeof(TFila));
  novo->dado = informacao;
  novo->next = NULL;

  if (fila == NULL)
    fila = novo;
  else{ 
    ultimo = fila;
    while (ultimo->next != NULL){
        ultimo = ultimo->next;
    }
    ultimo->next = novo;
    }
}


void dequeue(){
  TFila * destroyer = fila;
  fila = fila->next;
  free(destroyer);
}

void listar(){
  TFila * ultimo;
  printf("\n\nListando\n\n");
  for (ultimo = fila; ultimo != NULL; ultimo = ultimo->next){
    printf("%d ",ultimo->dado);
  }
}

void bubbleSort(){
  int temp;
  
  for (TFila * ultimo = fila; ultimo != NULL; ultimo = ultimo->next){
    for (TFila * penultimo = fila; penultimo->next != NULL; penultimo = penultimo->next){
      if (penultimo->dado > penultimo->next->dado){
        temp = penultimo->dado;
        penultimo->dado = penultimo->next->dado;
        penultimo->next->dado = temp;
      }
    }
  }
}

int main(int argc, char** argv) {

  enqueue(5);
  enqueue(4);
  enqueue(3);
  enqueue(2);
  enqueue(1);

  listar();
  bubbleSort();
  listar();

  return (EXIT_SUCCESS);
}
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

int main() {

  int i = 0;

  while (++i <= 10){
    enqueue(i);
  }

  listar();
  dequeue();
  dequeue();
  listar();

  return (EXIT_SUCCESS);
}

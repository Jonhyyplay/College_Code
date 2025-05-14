#include <stdio.h>
#include <stdlib.h>

typedef struct SFila {
  int dado;
  struct SFila * next;
  struct SFIla * prev;
} TFila;
 
 //Sentinela
TFila * fila = NULL;

void enqueue(int informacao){

  TFila * ultimo;
  TFila * novo;
  TFila * prev;//
  
  novo = malloc(sizeof(TFila));
  novo->dado = informacao;
  novo->next = NULL;
  novo->prev = NULL;//

  if (fila == NULL)
    fila = novo;
  else{ 
    ultimo = fila;
    while (ultimo->next != NULL){
        prev = ultimo;
        ultimo = ultimo->next;    
    }
    ultimo->next = novo;
    novo->prev = ultimo;//
    }
}

void dequeue(){
  TFila * destroyer = fila;
  fila = fila->next;
  fila->prev=NULL;//
  free(destroyer);
}

void listar(){
  TFila * ultimo;
  printf("\n\nListando\n\n");
  for (ultimo = fila; ultimo != NULL; ultimo = ultimo->next){
    printf("%d ",ultimo->dado);
  }
}

void listar_inverso(){
   TFila *fila;
   TFila* ultimo;
   
}

int main() {

  int i = 0;

  while (++i <= 10){
    enqueue(i);
  }

  while(fila != NULL){
    listar();
    dequeue();
  }

  return (EXIT_SUCCESS);
}
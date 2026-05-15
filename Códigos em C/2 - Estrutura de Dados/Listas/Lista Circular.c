#include <stdio.h>
#include <stdlib.h>

typedef struct SLista {
  int dado;
  struct SLista * next;
} TLista;
 
 //Sentinela
TLista * lista = NULL;

void adicionar(int posicao, int informacao){

  TLista * anterior;
  TLista * novo;
  TLista * ultimo;
  int cont;

  novo = malloc(sizeof(TLista));
  novo->dado = informacao;
  novo->next = NULL;

  if (lista == NULL){
    lista = novo;
    novo->next = lista;
  }
  else{ 
    if (posicao == 1){
      novo->next = lista;
      lista = ultimo;
      while (ultimo->next != lista){
        ultimo=ultimo->next;
      }
      ultimo->next = novo;
      novo = lista;
      return;
    }

    anterior = lista;
    for (cont = 2; cont < posicao && anterior->next != lista; cont++){ //de != NULL para != lista, para não entrar em loop
      anterior = anterior->next;
    }
    novo->next = anterior->next;
    anterior->next = novo;
    }
}


void remover(int posicao){
  TLista * destroyer;
  TLista * anterior = lista;
  TLista * ultimo;

  if (posicao == 1){ //ajusta o ponteiro do último nó para apontar ao novo primeiro nó
    destroyer = lista;
    ultimo = lista;
    while(ultimo->next != lista){
      ultimo = ultimo->next;
    }
    lista = lista->next;
    ultimo->next = lista;

  }else{
     for (int cont = 2; cont < posicao && anterior->next != lista; cont++){ //anterior->next != lista garante que não entre em loop
      anterior = anterior->next;
    }

    destroyer = anterior->next;
    anterior->next = destroyer->next;
  }

  free(destroyer);
}

void listar(){
  TLista * atual = lista;
  printf("\n\n\nListando\n\n\n");
  do{
    printf("%d", atual->dado);
    atual = atual->next;
  } while(atual != lista);
}

int main() {
  int leitura,posicao;


  while (1){
    printf("Informe a posição e o valor: ");
    scanf("%d %d",&posicao,&leitura);
    if (leitura == 0)
      break;
    
    adicionar(posicao,leitura);
  }

  listar();

  printf("\nQual posição deseja remover: ");
  scanf("%d",&posicao);
  remover(posicao);
  listar();
  

  return (EXIT_SUCCESS);
}

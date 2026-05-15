/*OBS: O código está bastante comentado. 
Isso pois estudarei o código da melhor maneira possível mais pra frente.
Não comentei linha por linha pois ficaria feio esteticamente*/

#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>

typedef struct SLista{  
    int dado;
    struct SLista *next;
}TLista; /*Definição de TLista, que representa um nó da lista encadeada. Feito aqui para não declarar TLista com struct sempre*/
//Sentinela
TLista *lista = NULL; /*Serve para apontar aos elementos da lista. É NULL pois a lista comaça vazia.*/

void inserir (int informacao, int posicao){
    TLista *novo = malloc(sizeof(TLista));
    novo->dado = informacao;
    novo->next = NULL;

  /* Condicional "se for a primeira posição ou se a lista tiver vazio" para inserir no início.*/
    if(posicao == 1 || lista == NULL){
      novo -> next = lista;
      lista = novo;
      return;
    }

    TLista *atual = lista;
    TLista *anterior = NULL;
    int i = 1;

  /*Aqui é para percorrer até encontrar a posição do novo nó a ser inserido*/
    while (atual != NULL && i < posicao){
      anterior = atual;
      atual = atual->next;
      i++;
    }
   /*Ajusta os ponteiros para inserir o nó na posição correta*/
    anterior -> next = novo;
    novo -> next = atual;
    
}

//novas variáveis  
void remover(int informacao){
    TLista *atual = lista;
    TLista *anterior = NULL;
  /*Percorrerá a lista até encontrar o nó a ser removido*/
    while(atual != NULL && atual->dado != informacao){
    anterior = atual;
    atual = atual->next;
    }
   /*Caso não exista o valor que queira remover, aparecerá a mensagem a seguir*/
    if(atual == NULL){
        printf("\n\nValor não presente");
        return;
    }
  /*Se o nó for o primeiro, ele ajusta a sentinela, para depois liberar o nó escolhido*/
    if(anterior == NULL){
    lista = atual->next;
    }else{
    anterior->next = atual->next;
    }

    free(atual);
}

void listar() {
    TLista *ultimo;
    printf("\n\nListando\n\n");
    for (ultimo = lista; ultimo != NULL; ultimo = ultimo->next) {
        printf("%d\n", ultimo->dado);
    }
    printf("\n");
}

int main() {
//  setlocale(LC_ALL, "Portuguese_Brazil");

  int leitura, posicao;
    while (1){
    printf("\n Informe o valor para INSERIR(0 p/ finalizar inserção): ");
    scanf("%d",&leitura);
    
    if (leitura == 0)
      break;

    printf("\n Informe a posição para INSERIR: ");
    scanf("%d", &posicao);
    
    inserir(leitura, posicao);
    listar();
  }

    while(1){
  printf("\n Informe o valor para REMOVER(0 para parar): ");
  scanf("%d", &leitura);
    
    if(leitura == 0)
      break;

    remover(leitura);
    listar();
  }

    return (EXIT_SUCCESS);
}
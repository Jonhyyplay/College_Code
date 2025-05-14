#include <stdio.h>
#include <stdlib.h>

#define TAM 5
int lista[TAM];

void adicionar (int v[], int posicao, int dado, int tamanho){
 if ((posicao < 0) || (posicao >= tamanho)){
   printf("\n\nEssa posição não existe.");
   return;
  }
  if (v[posicao] != 0 ){
    printf("\n\nPosição ocupada\n");
    return;
  }

  v[posicao] = dado;
}



void listar(int v[], int tamanho){
  int i;
  printf("\n\nListando\n");
  for (i = tamanho - 1; i >= 0; i--){
    printf("%d ", v[i]);
  }
}

void remover(int v[], int posicao, int tamanho){
  if ((posicao < 0) || (posicao >= tamanho)){
      printf("\n\nEssa posição não existe.\n\n");
      return;
  }

    v[posicao] = 0;
  
}

int buscar (int v[], int tamanho, int chave){
  for(int i = 0; i < tamanho; i++){
    if (v[i] == chave)
    return i;
  }
  return -1; // Deve retornar o índice do elemento. Como é uma variável inteira, deve retornar um inteiro (não NULL).
}


int main() {

  int leitura, posicao;

  while (1){
    printf("\n\nInforme a posição e o dado: ");
    scanf("%d %d",&posicao, &leitura);
    if (leitura == 0)
      break;
    adicionar(lista, posicao, leitura,TAM);
  }
    listar(lista,TAM);

  while (1){
    printf("\n\nInforme a posição que deseja remover: ");
    scanf("%d",&posicao);
    if (posicao == -1)
      break;
    remover(lista, posicao,TAM);
    listar(lista,TAM);
  }

  int key;
 
  while(1){
   printf("\n\nInforme a chave da busca: ");
   scanf("%d", &key);
   posicao = buscar(lista, TAM, key);
     if (posicao == -1)
        printf("\nChave não encontrada.\n\n");
    else
        printf("\nChave encontrada! Presente na posição %d", posicao);
    if (key == -1)
    break;
  }

  return (EXIT_SUCCESS);
}

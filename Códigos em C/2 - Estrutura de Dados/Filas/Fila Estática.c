#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int fila[TAM];

void enqueue (int v[], int dado, int tamanho){
  int i;

  for (i = 0; i < tamanho; i++){
    if (v[i] == 0){
      v[i] = dado;
      return;
    }
  }
  
  printf("\n\nA fila está cheia\n\n"); 
}

int quantidadeVazios(int v[], int tamanho){
    int i, cont = 0;
    for (i = 0; i < tamanho; i ++){
      if (v[i] == 0)
        cont++;
    }

    return cont;
  }

void listar(int v[], int tamanho){
  int i;
  printf("\n\nListando\n");
  for (i = 0; i < tamanho; i++){
    printf("%d ", v[i]);
  }
}

void dequeue(int v[], int tamanho){
  int i;
  for (i = 0; i < tamanho - 1; i++){
    v[i] = v[i + 1];
  }
  v[tamanho - 1] = 0;
}

int buscar (int v[], int tamanho, int chave) {
  for(int i = 0; i < tamanho; i++){
    if (v[i] == chave)
    return i;
  }
  return -1; // Deve retornar o índice do elemento. Como é uma variável inteira, deve retornar um inteiro (não NULL).
} 


int main() {

  int leitura;

  while (1){
    //vazios = quantidadeVazios(fila,TAM);
    //printf("Existem %d posições vazias;\n",vazios);//
    printf("Informe o dado: ");
    scanf("%d",&leitura);
    if (leitura == 0)
      break;
    enqueue(fila, leitura,TAM);
  }
  
  listar(fila,TAM);
  // dequeue(fila,TAM);
  // listar(fila,TAM);
  // dequeue(fila,TAM);
  // listar(fila,TAM);
  // dequeue(fila,TAM);
  // listar(fila,TAM);
  // dequeue(fila,TAM);
  // listar(fila,TAM);
  // dequeue(fila,TAM);
  // listar(fila,TAM);
  // dequeue(fila,TAM);

  int key;
  printf("\n\nInforme a chave da busca: ");
  scanf("%d", &key);
  int posicao = buscar(fila, TAM, key);
  if (posicao == -1)
  printf("\nChave não encontrada.\n\n");
  else
  printf("\nChave encontrada na posição %d", posicao);


  return (EXIT_SUCCESS);
}
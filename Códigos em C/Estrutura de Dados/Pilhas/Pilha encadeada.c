#include <stdio.h>
#include <stdlib.h>

typedef struct SPilha {
    int dado;
    struct SPilha *next;
} TPilha;

// Sentinela
TPilha *pilha = NULL;

void push(int informacao) { 
    TPilha *ultimo;
    TPilha *novo;
    novo = malloc(sizeof(TPilha)); //Aloca memória ao novo elemento
    novo->dado = informacao;
    novo->next = NULL;

    if (pilha == NULL)  // Se pilha estiver vazia, o novo elemento será o topo.
        pilha = novo;
    else {  
        ultimo = pilha; // Se ela já tem elementos, percorrerá até o último.
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        ultimo->next = novo; //Insere o novo elemento no final da pilha.
    }
}
 //Nessa parte, a função pop() é responsável por remover o último elemento da pilha.
 //Foi retirado a variável "destroyer" e colocado "prev"(antônimo de next).
void pop() { 
    TPilha *prev = NULL;
    TPilha *ultimo = pilha; //Aponta para o topo da pilha.
 //Aqui é caso tenha apenas um elemento.
    if (ultimo->next == NULL) { 
        free(pilha);
        pilha = NULL;
        return;
    }
 //Aqui, se tiver mais de um elemento. Nesse caso, percorrerá até o penúltimo elemento
   while (ultimo->next != NULL) {
        prev = ultimo; //Armazena o elemento atual
        ultimo = ultimo->next; //ùltimo avança para o próximo elemento
    }

    free(ultimo); //Libera o último elemento  
    prev->next = NULL; //O penúltimo se torna o novo último
}

void listar() {
    TPilha *ultimo;
    printf("\n\nListando\n\n");
    for (ultimo = pilha; ultimo != NULL; ultimo = ultimo->next) {
        printf("%d ", ultimo->dado);
    }
    printf("\n");
}

int main() {
    int i = 0;

    
    while (++i <= 10) {
        push(i);  
    }
 //Laço de repetição para que liste e remova os elementos da pilha (utilizei o while para não ficar repetindo as funções).
    while (pilha != NULL) {
        listar();
        pop();
    }
    listar(); // ùltima listagem para mostrar que está vazia.

    return (EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct SLista {
    int dado;
    struct SLista *next;
    struct SLista *prev;
} TLista;

TLista *lista = NULL;

void inserir(int informacao, int posicao) {
    TLista *novo = malloc(sizeof(TLista));
    novo->dado = informacao;
    novo->next = NULL;
    novo->prev = NULL;

    if (posicao == 1 || lista == NULL) {
        novo->next = lista;
        if (lista != NULL) {
            lista->prev = novo;
        }
        lista = novo;
        return;
    }

    TLista *atual = lista;
    int i = 1;

    while (atual->next != NULL && i < posicao - 1) {
        atual = atual->next;
        i++;
    }

    novo->next = atual->next;
    novo->prev = atual;

    if (atual->next != NULL) {
        atual->next->prev = novo;
    }

    atual->next = novo;
}

void remover(int informacao) {
    TLista *atual = lista;

    while (atual != NULL && atual->dado != informacao) {
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("\n\nValor não presente");
        return;
    }

    if (atual->prev != NULL) {
        atual->prev->next = atual->next;
    } else {
        lista = atual->next;
    }

    if (atual->next != NULL) {
        atual->next->prev = atual->prev;
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
    int leitura, posicao;
    while (1) {
        printf("\n Informe o valor para INSERIR(0 p/ finalizar inserção): ");
        scanf("%d", &leitura);

        if (leitura == 0)
            break;

        printf("\n Informe a posição para INSERIR: ");
        scanf("%d", &posicao);

        inserir(leitura, posicao);
        listar();
    }

    while (1) {
        printf("\n Informe o valor para REMOVER(0 para parar): ");
        scanf("%d", &leitura);

        if (leitura == 0)
            break;

        remover(leitura);
        listar();
    }

    return (EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct SInort {
    int dado;
    struct SInort *next;
    struct SInort *prev;
} TInSort;

TInSort *lista = NULL;

void inserir(int informacao, int posicao) {
    TInSort *novo = malloc(sizeof(TInSort));
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

    TInSort *atual = lista;
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

void listar() {
    TInSort *atual = lista;
    printf("\n\nListando\n\n");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->next;
    }
}

void insertionSort() {
    if (lista == NULL || lista->next == NULL) {
        return;
    }

    TInSort *atual = NULL;
    TInSort *anterior = lista;

    while (anterior != NULL) {
        TInSort *next = anterior->next;
        if (atual == NULL || atual->dado >= anterior->dado) {
            anterior->next = atual;
            if (atual != NULL) {
                atual->prev = anterior;
            }
            atual = anterior;
            atual->prev = NULL;
        } else {
            TInSort *temp = atual;
            while (temp->next != NULL && temp->next->dado < anterior->dado) {
                temp = temp->next;
            }
            anterior->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = anterior;
            }
            temp->next = anterior;
            anterior->prev = temp;
        }
        anterior = next;
    }
    lista = atual;
}

int main(int argc, char** argv) {
    inserir(5, 1);
    inserir(4, 2);
    inserir(3, 3);
    inserir(2, 4);
    inserir(1, 5);

    listar();
    insertionSort();
    listar();

    return 0;
}
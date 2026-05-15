#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore {
    struct SArvore *esq;
    int dado;
    struct SArvore *dir;
} TArvore;

TArvore *raiz;

void preOrdem(TArvore *no) {
    if (no == NULL)
        return;
    printf("%d ", no->dado);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

void ordem(TArvore *no) {
    if (no == NULL)
        return;
    ordem(no->esq);
    printf("%d ", no->dado);
    ordem(no->dir);
}

void posOrdem(TArvore *no) {
    if (no == NULL)
        return;
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ", no->dado);
}

void preencherArvore(TArvore *no) {
    if (no == NULL)
        return;
    int cont = 1, leitura = 0;
    TArvore *novo;
    while (cont <= 2) {
        printf("Informe um valor para o filho do nó %d (ou 0 para não inserir): ", no->dado);
        scanf("%d", &leitura);
        if (leitura == 0) {
            cont++;
            continue;
        }
        novo = malloc(sizeof(TArvore));
        novo->dado = leitura;
        novo->esq = NULL;
        novo->dir = NULL;
        if (cont == 1) no->esq = novo;
        else no->dir = novo;
        cont++;
    }
    preencherArvore(no->esq);
    preencherArvore(no->dir);
}

TArvore *buscar(TArvore *no, int chave) {
    if (no == NULL || no->dado == chave)
        return no;
    TArvore *busca = buscar(no->esq, chave);
    return (busca != NULL) ? busca : buscar(no->dir, chave);
}

// Remove um nó da árvore binária
TArvore *remover(TArvore *no, int chave) {
    if (no == NULL) return NULL;
    if (no->dado == chave) {
        if (no->esq == NULL && no->dir == NULL) { // Nó sem filhos
            free(no);
            return NULL;
        } else if (no->esq == NULL || no->dir == NULL) { // Nó com um filho
            TArvore *auxiliar = (no->esq != NULL) ? no->esq : no->dir;
            free(no);
            return auxiliar;
        } else { // Nó com dois filhos
            TArvore *auxiliar = no->dir;
            while (auxiliar->esq != NULL)
                auxiliar = auxiliar->esq;
            no->dado = auxiliar->dado;
            no->dir = remover(no->dir, auxiliar->dado);
        }
    } else {
        no->esq = remover(no->esq, chave);
        no->dir = remover(no->dir, chave);
    }
    return no;
}

// Altera o valor de um nó na árvore
void alterar(TArvore *no, int chave) {
    TArvore *alt = buscar(no, chave); 
    if (alt == NULL) {
        printf("Valor não encontrado na árvore.\n");
        return;
    }
    printf("Informe o novo valor para o nó %d: ", chave);
    scanf("%d", &alt->dado);
    printf("Valor alterado com sucesso!\n");
}

int main() {
    int chave, opcao;
    raiz = malloc(sizeof(TArvore));
    printf("Informe o valor da raiz: ");
    scanf("%d", &raiz->dado);
    raiz->esq = NULL;
    raiz->dir = NULL;
    preencherArvore(raiz);

    printf("\nExibindo a árvore em ordem simétrica (in-ordem):\n");
    ordem(raiz);
    printf("\n");

    while (1) {
        printf("\nInforme a chave a ser buscada (0 para sair): ");
        scanf("%d", &chave);
        if (chave == 0) break;

        TArvore *nodo = buscar(raiz, chave);
        if (nodo == NULL) {
            printf("Chave não encontrada\n");
        } else {
            printf("Chave encontrada: %d\n", chave);
            printf("Deseja alterar (1) ou remover (2) o nó? (0 para cancelar): ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                alterar(raiz, chave);
            } else if (opcao == 2) {
                raiz = remover(raiz, chave);
                printf("Nó removido com sucesso!\n");
            } else {
                printf("Nenhuma ação foi realizada.\n");
            }
        }

        // Exibe a árvore após a modificação (ajuda a ter uma noção de como a árvore está)
        printf("\nÁrvore atual\n");
        ordem(raiz);
        printf("\n");
    }
    return EXIT_SUCCESS;
}
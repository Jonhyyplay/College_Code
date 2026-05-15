#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore { //Esse é o tipo de dado que será armazenado em cada nó da árvore. 
    struct SArvore *esq;
    int dado;
    struct SArvore *dir;
} TArvore;

TArvore *raiz;

void preOrdem(TArvore *no){
    if (no == NULL)
        return;
    printf("%d ", no->dado);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

void ordem(TArvore * no){
    if (no == NULL)
        return;
    ordem(no->esq);
    printf("%d ",no->dado);
    ordem(no->dir);
}

void posOrdem(TArvore * no){
    if (no == NULL)
        return;
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ",no->dado);
}

void preencherABB( TArvore *no, int info){
    if (no == NULL)
        return;

    TArvore * novo;
    if (info < no->dado){
        if (no->esq == NULL){
            novo = malloc(sizeof(TArvore)); //aloca memória para um novo nó
            novo->dado = info; // atribui o valor informado ao novo nó
            novo->dir = novo->esq = NULL; // o campo que eu guardo o valor nos campos dir e esq recebem nulo 
            no->esq = novo; // adiciona o novo nó à esquerda do nó atual
        }else
            preencherABB(no->esq, info); // caso o nó não seja nulo, chama a função recursivamente para o nó à esquerda
    }else if (info > no->dado){
        if (no->dir == NULL){
            novo = malloc(sizeof(TArvore));
            novo->dado = info;                        //aqui repete os mesmo processo do if anterior, mas agora para o lado direito
            novo->dir = novo->esq = NULL;
            no->dir = novo;
        }else
            preencherABB(no->dir, info);
    }else{
        printf("Não é possível inserir valores duplicados numa árvore binária de busca"); // caso o valor seja igual ao nó atual, exibe a mensagem de erro (não adicionando valor à árvore)
    }

}

TArvore *buscarBinaria(TArvore *no, int chave) { //Em vez de int, buscar retorna um ponteiro para um nó (TArvore*), pois a função retorna o nó que contém a chave buscada
        if (no == NULL)
        return NULL; // Se não for igual, retorna NULL (ou posso retornar no), indicando que a chave não foi encontrada

        if (no->dado == chave) // Verifica se o dado do nó atual é igual à chave buscada
            return no; // Se for igual, retorna o nó atual
        
        if (chave < no->dado) { // Verifica se a chave é menor que o dado do nó atual caso não for igual (mesma coisa se for maior)
            return buscarBinaria (no->esq, chave); // Se não for igual, verifica se ela é menor que o dado do nó atual, podendo avançar para o nó à esquerda (chamada recursiva para subarvore esquerda)
        } else {
            return buscarBinaria (no->dir, chave); // Se não for igual e a chave não for menor, avança para o nó à direita (chamada recursiva para subarvore direita)
        }
}


int main() {

    int leitura;

    raiz = malloc(sizeof(TArvore));
    printf("Informe o valor da raiz: ");
    scanf("%d",&raiz->dado);
    raiz->esq = NULL;
    raiz->dir = NULL;
    //preencherArvore(raiz);

    while (1){
        printf("Informe o valor que será inserido na árvore: ");
        scanf("%d",&leitura);
        if (leitura == 0)
            break;
        preencherABB(raiz, leitura);
    }

    ordem(raiz); //Aqui eu escolho a ordem que a árvore será exibida (preOrdem, ordem ou posOrdem)

    int chave;

    while(1){
     printf("\n\nInforme a chave a ser buscada: ");
     scanf("%d", &chave);
     TArvore * valor = buscarBinaria(raiz, chave); //Serve para chamar a função Buscar p/ encontrar a chave informada. Retorna um ponteiro para um nó (TArvore*).
     
     if (chave == 0)
     break;
     
     if (valor == NULL){
        printf("\nChave não encontrada\n\n");
     } else {
        printf("\nChave encontrada: valor %d\n\n", chave);
     }
    }

    return (EXIT_SUCCESS);
}
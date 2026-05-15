#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore{
    struct SArvore * filho;
    int dado;
    struct SArvore * irmao;
}TArvore;

TArvore * raiz;

void profundidade(TArvore * no){
    if (no == NULL)
        return;

    printf("%d ",no->dado);
    profundidade(no->filho);
    profundidade(no->irmao);
}

void largura(TArvore * no){
    if (no == NULL)
        return;

    printf("%d ",no->dado);
    largura(no->irmao);
    largura(no->filho);
}

void preencherArvore(TArvore * no){
    if (no == NULL)
      return;

    TArvore * novo;
    TArvore * irmao;
    int leitura;

    while (1){
        printf("Informe o valor do filho de %d: ",no->dado);
        scanf("%d",&leitura);
        if (leitura == 0)
            break;

        novo = malloc(sizeof(TArvore));
        novo->dado = leitura;
        novo->filho = novo->irmao = NULL;

        if (no->filho == NULL){
            no->filho = novo;
            irmao = novo;
        }
        else {
            irmao->irmao = novo;
            irmao = novo;
        }

    }

    preencherArvore(no->filho);
    preencherArvore(no->irmao);
}



int main(int argc, char** argv) {

    int leitura;

    
    raiz = malloc(sizeof(TArvore));
    //printf("Informe o valor da raiz: ");
    raiz->dado = 1;
    raiz->filho = NULL;
    raiz->irmao = NULL;

    /*
  
    raiz->filho = malloc(sizeof(TArvore));
    raiz->filho->dado = 2;
    raiz->filho->filho = malloc(sizeof(TArvore));
    
    raiz->filho->filho->dado = 9;
    raiz->filho->filho->filho = NULL;

    raiz->filho->filho->irmao = malloc(sizeof(TArvore));
    raiz->filho->filho->irmao->dado = 10;
    raiz->filho->filho->irmao->filho = NULL;
    raiz->filho->filho->irmao->irmao = NULL;

    raiz->filho->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->dado = 3;

    raiz->filho->irmao->filho = malloc(sizeof(TArvore));
    raiz->filho->irmao->filho->dado = 11;
    raiz->filho->irmao->filho->irmao = NULL;

    raiz->filho->irmao->filho->filho = malloc(sizeof(TArvore));
    raiz->filho->irmao->filho->filho->dado = 15;
    raiz->filho->irmao->filho->filho->filho = NULL;
    raiz->filho->irmao->filho->filho->irmao = NULL;

    raiz->filho->irmao->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->dado = 4;

    raiz->filho->irmao->irmao->filho = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->filho->dado = 12;
    raiz->filho->irmao->irmao->filho->filho = NULL;

    raiz->filho->irmao->irmao->filho->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->filho->irmao->dado = 13;
    raiz->filho->irmao->irmao->filho->irmao->filho = NULL;
    raiz->filho->irmao->irmao->filho->irmao->irmao = NULL;

    raiz->filho->irmao->irmao->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->dado = 5;
    raiz->filho->irmao->irmao->irmao->filho = NULL;

    raiz->filho->irmao->irmao->irmao->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->irmao->dado = 6;

    raiz->filho->irmao->irmao->irmao->irmao->filho = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->irmao->filho->dado = 14;
    raiz->filho->irmao->irmao->irmao->irmao->filho->irmao = NULL;

    raiz->filho->irmao->irmao->irmao->irmao->filho->filho = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->dado = 16;
    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->filho = NULL;

    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->irmao->dado = 17;
    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->irmao->filho = NULL;

    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->irmao->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->irmao->irmao->dado = 18;
    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->irmao->irmao->filho = NULL;
    raiz->filho->irmao->irmao->irmao->irmao->filho->filho->irmao->irmao->irmao = NULL;

    raiz->filho->irmao->irmao->irmao->irmao->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->irmao->irmao->dado = 7;
    raiz->filho->irmao->irmao->irmao->irmao->irmao->filho = NULL;

    raiz->filho->irmao->irmao->irmao->irmao->irmao->irmao = malloc(sizeof(TArvore));
    raiz->filho->irmao->irmao->irmao->irmao->irmao->irmao->dado = 8;
    raiz->filho->irmao->irmao->irmao->irmao->irmao->irmao->filho = NULL;
    raiz->filho->irmao->irmao->irmao->irmao->irmao->irmao->irmao = NULL;
    */

    preencherArvore(raiz);
    profundidade(raiz);





/*
    while (1){
        printf("Informe o valor que será inserido na árvore: ");
        scanf("%d",&leitura);
        if (leitura == 0)
            break;
        preencherABB(raiz, leitura);
    }
    

    */   

    return (EXIT_SUCCESS);
}

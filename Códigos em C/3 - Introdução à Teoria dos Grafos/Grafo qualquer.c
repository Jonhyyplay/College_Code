#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct SNo{
    int dado;
    _Bool visitado;
    struct SConexao * listaConexoes;
    struct SNo * next; 
}TNo;

typedef struct SConexao{
    TNo * no;
    float peso;
    struct SConexao * next;
}TConexao;

TNo * primeiro = NULL;
TNo * ultimo = NULL;

TNo * buscar (int valor){
    TNo * last = primeiro;
    while (last != NULL){
        if (last->dado == valor)
            return last;
        last = last->next;
    }
    return NULL;
}

TNo * adicionarNo (int info){

    TNo * novo;

    novo = buscar(info);
    if (novo != NULL)
        return novo;
        
    novo = malloc(sizeof(TNo));
    novo->dado = info;
    novo->visitado = FALSE;
    novo->listaConexoes = NULL;
    novo->next = NULL;

    if (primeiro == NULL) 
        primeiro = novo;
    else
        ultimo->next = novo;

    ultimo = novo;

    return novo;
}

void listar (){
    TNo * last = primeiro;

    printf("\n\nListando\n\n");
    while (last != NULL){
        printf("%d ", last->dado);
        last = last->next;
    }
}   

void conectarNos(int dado1, int dado2, float pesoNo){

    TNo * noOrigem, * noDestino;
    TConexao * ultimaConexao;

    noOrigem = adicionarNo(dado1);
    noDestino = adicionarNo(dado2);

    TConexao * novaConexao = malloc(sizeof(TConexao));
    novaConexao->no = noDestino;
    novaConexao->peso = pesoNo;
    novaConexao->next = NULL;

    if (noOrigem->listaConexoes == NULL){
        noOrigem->listaConexoes = novaConexao;
    }else{
        ultimaConexao = noOrigem->listaConexoes;
        while (ultimaConexao->next != NULL){
            ultimaConexao = ultimaConexao->next;
        }
        ultimaConexao->next = novaConexao;
    }

}

void caminhoSimples(TNo * no){
    if (no == NULL)
        return;

    printf("Nó: %d\n",no->dado);
    no->visitado = TRUE;

    TConexao * ultimaConexao = no->listaConexoes;
    while (ultimaConexao != NULL){
        if (ultimaConexao->no->visitado == FALSE){
            printf("Peso da conexão com %d é %.2f\n", ultimaConexao->no->dado, ultimaConexao->peso);
            caminhoSimples(ultimaConexao->no);
        }
        ultimaConexao = ultimaConexao->next;
    }

}

int main() {

    int leitura;
    int leitura2;
    float peso;

    while (1){
        printf("\n\nInforme o valor 1: ");
        scanf("%d", &leitura);
        printf("\n\nInforme o valor 2: ");
        scanf("%d", &leitura2);
        printf("\n\nInforme o peso entre os valores: ");
        scanf("%f", &peso);
        if (leitura == 0) 
            break;

        if (leitura2 == 0)
            adicionarNo(leitura);
        else
            conectarNos(leitura, leitura2, peso);
    }  

    caminhoSimples(primeiro);
    
    return (EXIT_SUCCESS);
}